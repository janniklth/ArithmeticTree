#pragma once

#include <iostream>
#include <string>
#include "Token.hpp"
#include <sstream>

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
        // if tree is empty
        if (getValue() == "") {
            return 0;
        }


        if (!getLeft() && !getRight()) {
            // Leaf node (Operand)
            std::istringstream iss(getValue());
            int value;
            iss >> value;
            return value;
        }

        int leftValue = left->eval();
        int rightValue = right->eval();

        if (getValue() == "+") {
            return leftValue + rightValue;
        } else if (getValue() == "-") {
            return leftValue - rightValue;
        } else if (getValue() == "*") {
            return leftValue * rightValue;
        } else if (getValue() == "/") {
            return leftValue / rightValue;
        }
        return 1; // Default case (should not reach here)
    }

    string prefixReturn = "";

    string prefix()
	{
        prefixReturn += getValue();
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
        infixReturn += getValue();
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