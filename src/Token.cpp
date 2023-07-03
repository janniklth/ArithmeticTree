//
// Created by Jannik Loth on 03.07.23.
//

#include "Token.hpp"

// method to get the order of the node in the infix representation (important for visualization)
int Token::getOrd()
{
    return m_ord;
}

// method to get the type of the token
char Token::getType()
{
    return m_type;
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

// method to get the number of nodes in the tree
int Token::nodes()
{
    return 1;
}

// method to get the depth of the tree
int Token::depth()
{
    return 1;
}


