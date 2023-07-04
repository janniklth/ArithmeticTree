#pragma once

#include <iostream>
#include <string>
#include "Token.hpp"

/*
 * Baumknoten und Token zur Darstellung einer Zahl.
 */
class Number : public Token
{
    
	int number;

	// to implement ...
public:

    Number() {} // DIESEN LEEREN STANDARDKONSTRUKTOR NICHT LÖSCHEN

	Number(int i) {
        /* cout << "Number added: " << i << endl; */
        number = i;
        m_value = to_string(i);
        m_tokenType = TokenType::NUMBER;
    }
    
    int eval() 
	{

        // to implement ...
        
        cout << "Die Methode Number.eval ist noch nicht implementiert!" << endl;

        return 1; // remove this line
    }
    
    string prefix() 
	{
     string prefixReturnNumber = "";

     // Jannik implements a function that return value of number
     prefixReturnNumber = " number ";

        return prefixReturnNumber; // remove this line
    }
    string infix()
    {
        string infixReturnNumber = "";

        // Jannik implements a function that return value of number
        infixReturnNumber = " number ";

    return infixReturnNumber;
    }

	string postfix() 
	{
        string postfixReturnNumber = "";

        // Jannik implements a function that return value of number
        postfixReturnNumber = " number ";

        return postfixReturnNumber;
    }
    
    /*
     * Nummeriert den Baum ausgehend vom aktuellen Knoten unter Verwendung eines Zählers
	 * in Infix-Reihenfolge durch (wichtig für die Visualisierung).
     * 
     * Parameter: o der Zähler
     */
    void order(Order o) 
	{ 
		 setOrd(++o.counter); 
	}
};