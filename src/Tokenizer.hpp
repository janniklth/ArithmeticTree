#include <string>
#include <vector>

#include "Num.hpp"
#include "Bracket.hpp"
#include "Op.hpp"
#include "string.h"
#include "math.h"


using namespace std;

class Tokenizer
{

    string src;

public:
    // overloaded constructor
    Tokenizer(string s)
    {
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht
        // über die String-Grenze zu laufen
    }

    // splits a string into tokens
    // return type is a vector of pointers to tokens
    vector<Token *> *tokenize()
    {
        // vector that saves the single tokens as strings
        vector<string> stringVector;       //Testing purposes

        // given code from the exercise
        vector<Token *> *tokens = new vector<Token *>();
        vector<Token *>::iterator i = tokens->begin();

        // length of the string for the loop
        int stringLength = src.length();


        // iterate over every single char in the string
        for (int i = 0; i < stringLength; i++)
        {

            // check if the current char is a bracket and push a new Bracket object to the vector
            if (src[i] == '(' || src[i] == ')')
            {
                tokens->push_back(new Bracket(src[i]));

                cout << "Bracket: " << src[i] << endl;
            }

            // check if the current char is an operator (+, -, *, /) and push a new Op object to the vector
            else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/')
            {
                tokens->push_back(new Op(src[i]));

                cout << "Operator: " << src[i] << endl;
            }

            // check if the current char is a number (0-9) and push a new Num object to the vector
            else if (isdigit(src[i]))
            {
                int number = atoi(src.substr(i, stringLength).c_str());
                tokens->push_back(new Num(number));

                cout << "Number: " << number << endl;

                i += log10(number);
            }
        }

        // print out vector tokens for testing purposes
        cout << "Testausgabe: " << endl;
        cout << "Einzelne Tokens: " << endl;
        for (int i = 0; i < stringVector.size(); i++) {
            cout << stringVector[i] << endl;
        }

        return tokens;
    }

};