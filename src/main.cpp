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

/// function to parse arguments and check if all arguments are given
/// @param argc: number of arguments
/// @param argv: list of arguments
/// @param mode: pointer to the mode var
/// @param expression: pointer to the input var
/// @return: true if all arguments are given, false if not
bool parse_arguments(int argc, char *argv[], char *mode, string *expression)
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
    if (!argument_m) {
        cout << "ERROR: argument -m for the mode is missing" << endl;
        is_successful = false;
    }
    if (!argument_e) {
        cout << "ERROR: argument -e for the expression is missing" << endl;
        is_successful = false;
    }
    if (!is_successful) { return is_successful; };

    // loop over all arguments to read the arguments
    for (int i = 0; i < argc - 1; i++) {

        int bracket_counter = 0;
        bool bracket_counting_successful = false;

        // check for expression
        if (!strcmp(argv[i], "-e")) {
            // concatenate all arguments until all brackets are closed
            do {
                for (int j = 0; j < strlen(argv[i + 1]); j++) {
                    // check if the next charachter is a opening bracket
                    if (argv[i + 1][j] == '(') {
                        bracket_counter++;
                        bracket_counting_successful = true;
                    }

                        // check if the next charachter is a closing bracket
                    else if (argv[i + 1][j] == ')') {
                        bracket_counter--;
                        bracket_counting_successful = true;
                    }

                    // concatenate the charachter to the expression
                    *expression += argv[i + 1][j];
                }
                // step to the next argument
                i++;
            } while (bracket_counter != 0);

            // check if the expression is empty or ni brackets where found
            if (!bracket_counting_successful) {
                cout
                        << "ERROR: argument for expression (-e) is not correct. "
                        << " \nPlease use -e <expression> and expression: ((1+2)*3), all-encompassing brackets are important!"
                        << endl;
                is_successful = false;
            }
        }

            // check for mode
        else if (!strcmp(argv[i], "-m")) {
            if (!strcasecmp(argv[i + 1], "PREFIX")) {
                *mode = '<';
                i++;
            } else if (!strcasecmp(argv[i + 1], "INFIX")) {
                *mode = '|';
                i++;
            } else if (!strcasecmp(argv[i + 1], "POSTFIX")) {
                *mode = '>';
                i++;
            } else {
                cout << "ERROR: argument for mode (-m) is not correct: " << argv[i + 1]
                     << " please use -m <mode> and mode: infix, prefix or postfix" << endl;
                is_successful = false;
            }
        }
    }
    return is_successful;
}

// main loop
int main(int argc, char *argv[])
{
#if defined(WIN32) || defined(WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif

    Evaluator e;
    string input = " ";
    char mode = 0;

    if (!(parse_arguments(argc, argv, &mode, &input))) {
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
