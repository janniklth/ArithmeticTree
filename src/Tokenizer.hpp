/*
 *  author:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 *  version:    1.0
 */
#ifndef ARITHMETIC_TREE_TOKENIZER_HPP
#define ARITHMETIC_TREE_TOKENIZER_HPP

#include <string>
#include <vector>

#include "Token Classes/Number.hpp"
#include "Token Classes/Bracket.hpp"
#include "Token Classes/Operator.hpp"
#include "Token Classes/Token.hpp"
#include "Utilities.hpp"

#include "string.h"
#include "math.h"

using namespace std;

class Tokenizer
{
public:
    // overloaded constructor
    Tokenizer(string s)
    {
        m_src = s + " "; // space at the end to avoid out of range errors
    }

    /// splits a string into tokens from type Number, Operator and Bracket
    /// @return vector<Token*>: the vector of tokens
    vector<Token *> *tokenize(Utilities::ParseMode mode);

private:
    string m_src;
};

#endif //ARITHMETIC_TREE_TOKENIZER_HPP