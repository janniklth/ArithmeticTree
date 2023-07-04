#pragma once

#include <iostream>
#include <string>
#include "Token.hpp"

/*
 * Baumknoten und Token zur Darstellung eines Operators.
 */
class Operator : public Token
{

    Token *left, *right;

public: 

    /*
     * Erzeugt einen neuen Operator-Knoten.
     * 
     * Parameter: t der Typ des Knotens: '+', '-', '*' oder '/'
     * Parameter: l der linke Unterbaum
     * Parameter: r der rechte Unterbaum
     */
    Operator(string s, Token *l, Token *r)
	{
        m_value = s;
        m_tokenType = TokenType::OPERATOR;
        left = l;
        right = r;
    }
    
    /*
     * Erzeugt einen neuen Operator-Token.
     * 
     * Parameter: t der Typ des Tokens: '+', '-', '*' oder '/'
     */
    Operator(char s)
	{
        m_tokenType = TokenType::OPERATOR;
        m_value = s;
        left = NULL;
        right = NULL;
		// cout << "Operator added: " << t << endl;
    }

    Token *getLeft() override
    {
        return left;
    }

    Token *getRight() override
    {
        return right;
    }

    int returnValue = 0;
    int eval() 
	{

        return 0; // Default case (should not reach here)
    }

    string prefix()
	{
        string prefixReturn = "";

        prefixReturn += getValue();
        prefixReturn += left->prefix();
        prefixReturn += right->prefix();

        return prefixReturn; // remove this line
    }

    string infix()
	{
        string infixReturn = "";

        // put an opening bracket to the start of the string
        if (left != NULL && right != NULL)
            infixReturn += "(";

        infixReturn += left->infix();
        infixReturn += getValue();
        infixReturn += right->infix();

        // put an closing bracket to the end of the string
        if (left != NULL && right != NULL)
            infixReturn += ")";

        return infixReturn; // remove this line
    }
    string postfix() 
	{
        string postfixReturn = "";

        postfixReturn += left->postfix();
        postfixReturn += right->postfix();
        postfixReturn += getValue();

        return postfixReturn; // remove this line
    }

    int nodes() 
	{

        // to implement ...

        cout << "Die Methode Operator.nodes ist noch nicht implementiert!" << endl;

        return 1; // remove this line
    }

    int depth() 
	{

        // to implement ...
                
        cout << "Die Methode Operator.depth ist noch nicht implementiert!" << endl;

        return 1; // remove this line
    }

    /*
     * Nummeriert den Baum ausgehend vom aktuellen Knoten unter Verwendung eines Zaehlers 
	 * in Infix-Reihenfolge durch (wichtig fuer die Visualisierung).
     * 
     * Parameter: o der Zaehler
     */
    void order(Order *o) 
	{
        left->order(o);
        setOrd(++o->counter);
        right->order(o);
    }

};