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

// function to parse arguments and check if all arguments are given
bool parse_arguments(int argc, char *argv[], char *mode, string *input)
{
    // initialise a var to store if the parsing was successful
    bool is_successful = true;

    // initialise three vars to store if all three wanted arguments are in the list
    bool argument_m = false, argument_e = false;

    // loop over all arguments to check if the arguments contains all three arguments
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-m") == 0) { argument_m = true; }
        if (strcmp(argv[i], "-e") == 0) { argument_e = true; }
    }

    // check if all arguments are given, if not throw a specific error an exit
    if (!argument_m) { cout << "ERROR: argument -m for the mode is missing" << endl; is_successful = false;}
    if (!argument_e) { cout << "ERROR: argument -e for the expression is missing" << endl; is_successful = false;}
    if (!is_successful) {return is_successful;};

    // loop over all arguments to read the arguments
    for (int i = 0; i < argc - 1; i++) {

        // check for expression
        if (!strcmp(argv[i], "-e")) {
            // put argument in the input var until an "-m"
            while (strcmp(argv[i + 1], "-m") != 0) {
                *input += argv[i + 1];
                i++;
            }
        }

        // check for mode
        else if (!strcmp(argv[i], "-m"))
        {
            if (!strcasecmp(argv[i + 1], "PREFIX"))
            {
                *mode = '<';
                i++;
            }
            else if (!strcasecmp(argv[i + 1], "INFIX"))
            {
                *mode = '|';
                i++;
            }
            else if (!strcasecmp(argv[i + 1], "POSTFIX"))
            {
                *mode = '>';
                i++;
            }
            else
            {
                cout << "ERROR: argument for mode (-m) is not correct: " <<  argv[i + 1] << endl;
                is_successful = false;
            }
        }
    }
    return is_successful;
}


int main(int argc, char* argv[])
{
    #if defined(WIN32) || defined(WIN64)
         SetConsoleOutputCP(CP_UTF8);
    #endif

    Evaluator e;
    string input = " ";
    char mode = 0;

    if (!(parse_arguments(argc, argv, &mode, &input))){
        cout << "ERROR: parsing arguments failed";
        return 1;
    }

    // print out the arguments
    std::cout << "\n\nRechenausdruck: " << input << std::endl;
    std::cout << "Zeichen: " << mode << std::endl;

    // evaluate the expression
    e.evaluate(input, mode);

    return 0;
}
