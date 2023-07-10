/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */


#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#endif

#include <iostream>
#include "Evaluator.hpp"

using namespace std;

// static var to count the nodes
static int node_counter;


int main(int argc, char* argv[])
{
    #if defined(WIN32) || defined(WIN64)
         SetConsoleOutputCP(CP_UTF8);
    #endif

    string input = " ";
    char mode = 0;
    Evaluator e;


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

    return 0;
}
