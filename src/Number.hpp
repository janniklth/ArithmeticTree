#pragma once

#include <iostream>
#include <string>
#include "Token.hpp"

/*
 * Baumknoten und Token zur Darstellung einer Zahl.
 */
class Number : public Token
{
    
	int m_number;

	// to implement ...
public:

    Number() {} // DIESEN LEEREN STANDARDKONSTRUKTOR NICHT LÖSCHEN

	Number(int i) {
        /* cout << "Number added: " << i << endl; */
        m_number = i;
        m_value = to_string(i);
        m_tokenType = TokenType::NUMBER;
    }

    int getMNumber() const {
        return m_number;
    }

    int eval() 
	{

        // to implement ...
        
        cout << "Die Methode Number.eval ist noch nicht implementiert!" << endl;

        return 1; // remove this line
    }
    
    string prefix() 
	{
         return " " + m_value + " ";  // remove this line
    }
    string infix()
    {
        return " " + m_value + " ";  // remove this line
    }

	string postfix() 
	{
        return " " + m_value + " ";  // remove this line
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