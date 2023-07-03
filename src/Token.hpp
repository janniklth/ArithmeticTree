#ifndef ARITHMETIC_TREE_TOKEN_HPP
#define ARITHMETIC_TREE_TOKEN_HPP


#include <string>
#include "Order.hpp"

using namespace std;

class Token 
{
public:
    /// Auswertung
    /// @return int: the result of the evaluation ????
    virtual int eval() = 0;

    /// Prefix-Representation
    /// @return string: the prefix representation
	virtual string prefix() = 0;

    /// Infix-Representation
    /// @return string: the infix representation
    virtual string infix() = 0;

    /// Postfix-Representation
    /// @return string: the postfix representation
    virtual string postfix() = 0;

    /// left subtree
    /// @return Token*: the left subtree
    Token* left() {
        return NULL;
    }
    /// right subtree
    /// @return Token*: the right subtree
    Token* right() {
        return NULL;
    }

    /// number of nodes in the tree
    /// @return int: the number of nodes in the tree
    int nodes();

    /// depth of the tree
    /// @return int: the depth of the tree
    int depth();

    /// numerates the tree starting from the current node using a counter in infix order (important for visualization)
    /// @param o: the counter
    void order(Order *o);


    // - - - - - - Getter and Setter - - - - - - -

    /// Getter for the type of the token
    /// @return char: the type of the token
    char getType();

    /// Getter for the order of the node in the infix representation (important for visualization)
    /// @return int: the index of the node
    int getOrd();

    /// Setter for the index of the node in the infix representation (important for visualization)
    /// @param o: the index of the node
    void setOrd(int o);


protected:
    char m_type;				// Typ des Tokens / Knotens
    int m_ord;					// Reihenfolge fuer die Visualisierung

};

#endif //ARITHMETIC_TREE_TOKEN_HPP