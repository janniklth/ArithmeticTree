#pragma once

#include <iostream>
#include <string>
#include "Token.hpp"

/*
 * Token zur Darstellung einer Klammer.
 */
class Bracket : public Token 
{

public:

    /*
     * Erzeugt einen neuen Klammer-Token.
     * 
     * Parameter: t Typ der Klammer: '(' oder ')'
     */
    Bracket(char s)
    {
        m_tokenType = TokenType::BRACKET;
        m_value = s;
    }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: 0
     */
    int eval()
    {
        return 0;
    }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: leerer String
     */
    string prefix() { return ""; }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: leerer String
     */
    string infix() { return ""; }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: leerer String
     */
    string postfix() { return ""; }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Parameter: o Dummy-Parameter
     */
    void order(Order o) {}
};