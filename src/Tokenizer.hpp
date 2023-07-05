#include <string>
#include <vector>

#include "Number.hpp"
#include "Bracket.hpp"
#include "Operator.hpp"
#include "string.h"
#include "math.h"
#include "Token.hpp"

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
    // return m_type is a vector of pointers to tokens
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
            }

            // check if the current char is an operator (+, -, *, /) and push a new Operator object to the vector
            else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/')
            {
                tokens->push_back(new Operator(src[i]));
                Operator::incNodes();

                //cout << "Operator: " << src[i] << endl;
            }

            // check if the current char is a m_number (0-9) and push a new Number object to the vector
            else if (isdigit(src[i]))
            {
                int number = atoi(src.substr(i, stringLength).c_str());
                tokens->push_back(new Number(number));

                Operator::incNodes();

                // increase i by the length of the number
                i += log10(number);
            }
        }

        return tokens;
    }

};