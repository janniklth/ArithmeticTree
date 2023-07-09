/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#include <iostream>
#include "Evaluator.hpp"

using namespace std;


// static var to count the nodes
static int node_counter;


int main(int argc, char* argv[])
{
    string input = " ";
    char mode = 0;
    Evaluator e;

    // test strings
    string infix = "((10 + 20) * 30)";
    string infix2 = "( ( (2 + 2) + (2 + 2) ) * ( (10 / 5) * 3) )";
    string postfix = "10 20 + 30 *";
    string prefix = "+ 10 20";

    // check if enough arguments are given
    if (argc < 3) {
        std::cout << "Zu wenige Argumente angegeben." << std::endl;
        return 1;
    }

    // read the inout string and combine all arguments to the expression, even if they are separated by spaces
    for (int i = 1; i < argc - 1; i++) {
        input += argv[i];
    }

    // give the last parameter to mode
    mode = argv[argc - 1][0];

    // print out the arguments
    std::cout << "Rechenausdruck: " << input << std::endl;
    std::cout << "Zeichen: " << mode << std::endl;

    // evaluate the expression
    e.evaluate(input, mode);

    // Test cases for test strings
    //e.evaluate(prefix, '<');
    //e.evaluate(infix2, '|');
    //e.evaluate(postfix, '>');

    return 0;
}
