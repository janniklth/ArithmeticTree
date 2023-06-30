#pragma once

#include <iostream>
#include <string>
#include "Token.hpp"

/*
 * Baumknoten und Token zur Darstellung einer Zahl.
 */
class Num : public Token 
{
    
	int number;

	// to implement ...
public:

    Num() {} // DIESEN LEEREN STANDARDKONSTRUKTOR NICHT LÖSCHEN
	Num(int i) { /* cout << "Number added: " << i << endl; */ number = i;}
    
    int eval() 
	{

        // to implement ...
        
        cout << "Die Methode Num.eval ist noch nicht implementiert!" << endl;

        return 1; // remove this line
    }
    
    string prefix() 
	{

        // to implement ...
        
        cout << "Die Methode Num.prefix ist noch nicht implementiert!" << endl;

        return ""; // remove this line
    }
    string infix() 
	{

        // to implement ...
        
        cout << "Die Methode Num.infix ist noch nicht implementiert!" << endl;

        return ""; // remove this line
    }

	string postfix() 
	{

        // to implement ...
                
        cout << "Die Methode Num.postfix ist noch nicht implementiert!" << endl;

        return ""; // remove this line
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