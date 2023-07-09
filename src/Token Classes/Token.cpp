/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#include "Token.hpp"


// initialize the static variable
int Token::node_counter = 0;


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

// method to numerate the m_tree starting from the current node using a counter in infix order (important for visualization)
void Token::order(Order *o)
{

}

// method to get the number of nodes in the tree
int Token::nodes()
{
    return node_counter;
}

// method to get the depth of a tree
int Token::depth(Token* root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max(depth(root->getLeft()), depth(root->getRight()));
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

// method to increase the number of nodes in the tree
void Token::incNodes()
{
    node_counter++;
}
