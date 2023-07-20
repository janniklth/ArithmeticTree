//
// Created by Jannik Loth on 11.07.23.
//

#ifndef ARITHMETICTREE_UTILITIES_HPP
#define ARITHMETICTREE_UTILITIES_HPP

#include <iostream>
#include <cstring>

using namespace std;

class Utilities
{
public:

    /// enum to store the different parse modes
    enum class ParseMode
    {
        PREFIX,
        INFIX,
        POSTFIX
    };

    /// method to convert ParesMode to string
    /// @param mode: the ParseMode to be converted
    /// @return string: the converted ParseMode
    static string parseModeToString(ParseMode mode);

    /// function to parse arguments and check if all arguments are given
    /// @param argc: number of arguments
    /// @param argv: list of arguments
    /// @param mode: pointer to the mode var
    /// @param expression: pointer to the input var
    /// @return: true if all arguments are given, false if not
    static bool parse_arguments(int argc, char *argv[], ParseMode *mode, std::string *expression);

};


#endif //ARITHMETICTREE_UTILITIES_HPP
