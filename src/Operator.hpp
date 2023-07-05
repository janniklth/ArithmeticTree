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

        int left_value = left->eval();
        int right_value = right->eval();

        if (getValue() == "+")
        {
            return left_value + right_value;
        }
        else if (getValue() == "-")
        {
            return left_value - right_value;
        }
        else if (getValue() == "*")
        {
            return left_value * right_value;
        }
        else if (getValue() == "/")
        {
            return left_value / right_value;
        }
        return 1; // Default case (should not reach here)
    }


    string prefix()
	{
        string prefix_return = "";

        prefix_return += getValue() + " ";
        prefix_return += left->prefix();
        prefix_return += right->prefix();

        return prefix_return; // remove this line
    }

    string infix()
	{
        string infix_return = "";

        // put an opening bracket to the start of the string
        if (left != NULL && right != NULL)
            infix_return += "(";


        infix_return += left->infix();
        infix_return += " " + getValue() + " ";
        infix_return += right->infix();

        // put an closing bracket to the end of the string
        if (left != NULL && right != NULL)
            infix_return += ")";

        return infix_return; // remove this line
    }
    string postfix() 
	{
        string postfix_return = "";


        postfix_return += left->postfix();
        postfix_return += right->postfix();
        postfix_return += getValue() + " ";

        return postfix_return; // remove this line
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