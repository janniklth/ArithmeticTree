#ifndef ARITHMETIC_TREE_TOKENIZER_HPP
#define ARITHMETIC_TREE_TOKENIZER_HPP

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
public:
    // overloaded constructor
    Tokenizer(string s)
    {
        m_src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht
        // über die String-Grenze zu laufen
    }

    /// splits a string into tokens from type Number, Operator and Bracket
    /// @return vector<Token*>: the vector of tokens
    vector<Token *> *tokenize();

private:
    string m_src;
};

#endif //ARITHMETIC_TREE_TOKENIZER_HPP