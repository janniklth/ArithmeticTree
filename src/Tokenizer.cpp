/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#include "Tokenizer.hpp"

// splits a string into tokens from type Number, Operator and Bracket
vector<Token *> *Tokenizer::tokenize()
{
    // vector that saves the single tokens as strings
    vector<string> stringVector;       //Testing purposes

    // given code from the exercise
    vector<Token *> *tokens = new vector<Token *>();
    vector<Token *>::iterator i = tokens->begin();

    // length of the string for the loop
    int stringLength = m_src.length();

    // iterate over every single char in the string
    for (int i = 0; i < stringLength; i++)
    {

        // check if the current char is a bracket and push a new Bracket object to the vector
        if (m_src[i] == '(' || m_src[i] == ')')
        {
            tokens->push_back(new Bracket(m_src[i]));
        }

            // check if the current char is an operator (+, -, *, /) and push a new Operator object to the vector
        else if (m_src[i] == '+' || m_src[i] == '-' || m_src[i] == '*' || m_src[i] == '/')
        {
            tokens->push_back(new Operator(m_src[i]));
            Operator::incNodes();
        }

            // check if the current char is a m_number (0-9) and push a new Number object to the vector
        else if (isdigit(m_src[i]))
        {
            int number = atoi(m_src.substr(i, stringLength).c_str());
            tokens->push_back(new Number(number));

            Operator::incNodes();

            // increase i by the length of the number
            i += log10(number);
        }
    }
    return tokens;
}
