//
// Created by Jannik Loth on 03.07.23.
//

#include "Token.hpp"

// method to get the order of the node in the infix representation (important for visualization)
int Token::getOrd()
{
    return m_ord;
}


// method to set the order of the node in the infix representation (important for visualization)
void Token::setOrd(int o)
{
    m_ord = o;
}

// method to numerate the tree starting from the current node using a counter in infix order (important for visualization)
void Token::order(Order *o)
{

}

// method to get the m_number of nodes in the tree
int Token::nodes()
{
    return 1;
}

// method to get the depth of the tree
int Token::depth()
{
    return 1;
}

// method to get the value of the token
string Token::getValue()
{
    return m_value;
}

// method to set the value of the token
void Token::setValue(string s)
{
    m_value = s;
}

// method to get the type of the token
TokenType Token::getTokenType()
{
    return m_tokenType;
}

// method to set the type of the token
void Token::setTokenType(TokenType t)
{
    m_tokenType = t;
}


