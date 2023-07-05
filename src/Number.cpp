//
// Created by Jannik Loth on 05.07.23.
//

#include "Number.hpp"

// evaluates the result of the tree/subtree
int Number::eval()
{
    // if tree is empty
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
    return m_value + " ";  // remove this line
}

// method to return the infix representation of the tree/subtree
string Number::infix()
{
    return m_value;  // remove this line
}

// method to return the postfix representation of the tree/subtree
string Number::postfix()
{
    return m_value + " ";  // remove this line
}

// numerates the tree starting from the current node using a counter in infix order, important for visualization
void Number::order(Order o)
{
    setOrd(++o.counter);
}

// - - - - - Getter and Setter - - - - -

// Getter for the number value of the node
int Number::getNumber() const
{
    return m_number;
}
