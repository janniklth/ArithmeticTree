#ifndef ARITHMETIC_TREE_TOKEN_HPP
#define ARITHMETIC_TREE_TOKEN_HPP


#include <string>
#include "Order.hpp"
#include "string"

using namespace std;


enum class TokenType
{
    NUMBER,
    OPERATOR,
    BRACKET
};


class Token 
{
public:
    /// Calculate the value of the expression
    /// @return int
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

    /// m_number of nodes in the tree
    /// @return int: the m_number of nodes in the tree
    int nodes();

    /// depth of the tree
    /// @return int: the depth of the tree
    int depth();

    /// numerates the tree starting from the current node using a counter in infix order (important for visualization)
    /// @param o: the counter
    void order(Order *o);


    // - - - - - - Getter and Setter - - - - - - -

    /// Getter for the order of the node in the infix representation (important for visualization)
    /// @return int: the index of the node
    int getOrd();

    /// Getter for the value of the token
    /// @return char: the value of the token
    string getValue();

    /// Getter for the type of the token
    /// @return TokenType: the type of the token
    TokenType getTokenType();

    /// Getter for the left subtree
    /// @return Token*: the left subtree
    virtual Token* getLeft()
    {
        return NULL;
    }

    /// Getter for the right subtree
    /// @return Token*: the right subtree
    virtual Token* getRight()
    {
        return NULL;
    }

    /// Setter for the index of the node in the infix representation (important for visualization)
    /// @param o: the index of the node
    void setOrd(int o);

    /// Setter for the value of the token
    /// @param v: the value of the token
    void setValue(string s);

    /// Setter for the type of the token
    /// @param t: the type of the token
    void setTokenType(TokenType t);


protected:
    int m_ord;                  // Reihenfolge fuer die Visualisierung
    string m_value;
    TokenType m_tokenType;
};

#endif //ARITHMETIC_TREE_TOKEN_HPP