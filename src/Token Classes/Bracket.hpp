#pragma once

#include <iostream>
#include <string>
#include "Token.hpp"


/// Bracket node class
/// @brief node class representing a bracket
class Bracket : public Token 
{
public:
    /// overloaded constructor, creates a new bracket node with the given value
    /// @param bracket: the value of the bracket node (´(´ or ´)´)
    Bracket(char bracket_value)
    {
        m_tokenType = TokenTypeABC::BRACKET;
        m_value = bracket_value;
    }

    /// Dummy-method, does nothing
    /// @return int: 0
    /// TODO: evaluate if its better to make the b ase function not pure virtual
    int eval() override
    {
        return 0;
    }

    /// Dummy-method, does nothing
    /// @return string: empty string
    /// TODO: evaluate if its better to make the b ase function not pure virtual
    string prefix() override
    {
        return "";
    }

    /// Dummy-method, does nothing
    /// @return string: empty string
    /// TODO: evaluate if its better to make the b ase function not pure virtual
    string infix() override
    {
        return "";
    }

    /// Dummy-method, does nothing
    /// @return string: empty string
    /// TODO: evaluate if its better to make the b ase function not pure virtual
    string postfix() override
    {
        return "";
    }

    /// Dummy-method, does nothing
    /// @param o: dummy parameter
    /// TODO: evaluate if its better to make the b ase function not pure virtual
    void order(Order o) {}
};