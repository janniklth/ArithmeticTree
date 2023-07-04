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
    Operator(char t, Token *l, Token *r)
	{
        m_type = t;
        left = l;
        right = r;
    }
    
    /*
     * Erzeugt einen neuen Operator-Token.
     * 
     * Parameter: t der Typ des Tokens: '+', '-', '*' oder '/'
     */
    Operator(char t)
	{
        m_type = t;
        left = NULL;
        right = NULL;
		// cout << "Operator added: " << t << endl;
    }

    Token* getLeft() { return left; }
    Token* getRight() { return right; }

    int eval() 
	{

        // to implement ...
        
        cout << "Die Methode Operator.eval ist noch nicht implementiert!" << endl;

        return 1; // remove this line
    }

    string prefixReturn = "";

    string prefix()
	{
        prefixReturn += getType();
        prefixReturn += left->prefix();
        prefixReturn += right->prefix();

        return prefixReturn; // remove this line
    }
    string infix() 
	{
        string infixReturn = "";

        if (left || right) {
            std::cout << "(";
        }

        infixReturn += left->infix();
        infixReturn += getType();
        infixReturn += right->infix();

        if (left || right) {
            infixReturn += ")";
        }

        return infixReturn; // remove this line
    }
    string postfix() 
	{
        string postfixReturn = "";

        postfixReturn += left->postfix();
        postfixReturn += right->postfix();
        postfixReturn += getType();

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