/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#include "Number.hpp"

// evaluates the result of the tree/subtree
int Number::eval()
{
    // return 0 if the tree is empty TODO: wirklich nötig dieser comment?
    if (getValue() == "") {
        return 0;
    }
    else {
        // turns string into int and returns the int value
        return stoi(getValue());
    }
}

// method to return the prefix representation of the tree/subtree
string Number::prefix()
{
    return m_value + " ";
}

// method to return the infix representation of the tree/subtree
string Number::infix()
{
    return m_value;
}

// method to return the postfix representation of the tree/subtree
string Number::postfix()
{
    return m_value + " ";
}

// - - - - - Getter and Setter - - - - -

// Getter for the number value of the node
int Number::getNumber() const
{
    return m_number;
}
