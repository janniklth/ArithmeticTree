/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */


#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#endif

#include <iostream>
#include "Evaluator.hpp"
#include "Utilities.hpp"


using namespace std;

// static var to count the nodes
static int node_counter;


// main loop
int main(int argc, char *argv[])
{
#if defined(WIN32) || defined(WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif

    Evaluator e;
    string input = " ";
    Utilities::ParseMode mode;

    if (!(Utilities::parse_arguments(argc, argv, &mode, &input))) {
        cout << "ERROR: parsing arguments failed";
        return 1;
    }

    // print out the arguments
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - INPUT - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "Expression: " << input << std::endl;
    std::cout << "Mode/Notation: " << Utilities::parseModeToString(mode) << "\n" << std::endl;

    // evaluate the expression
    e.evaluate(input, mode);

    return 0;
}
