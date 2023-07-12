//
// Created by Jannik Loth on 11.07.23.
//

#include "Utilities.hpp"

// method to convert ParesMode to string
string Utilities::parseModeToString(Utilities::ParseMode mode)
{
    switch (mode) {
        case ParseMode::PREFIX:
            return "PREFIX";
        case ParseMode::INFIX:
            return "INFIX";
        case ParseMode::POSTFIX:
            return "POSTFIX";
        default:
            return "ERROR";
    };
}

// method to parse arguments and check if all arguments are given
bool Utilities::parse_arguments(int argc, char **argv, Utilities::ParseMode *mode, std::string *expression)
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
    if (!is_successful) { return is_successful; }



    // loop over all arguments to read the arguments
    for (int i = 1; i < argc - 1; i++) {

        cout << "arg[" << i << "]: " << argv[i] << endl;
        cout << argc << endl;

        // check for expression
        if (!strcmp(argv[i], "-e")) {
            if (argv[i + 2] == nullptr || argv[i + 2][0] == '-') {
                *expression = argv[i + 1];
                i++;
            } else {
                cout << "ERROR: parameter value for argument -e is missing or in a wrong format\n       "
                     << "please it like -e <\"expression\">" << endl;
                i++;
                is_successful = false;
            }
        }
        // check for mode
        else if (!strcmp(argv[i], "-m")) {
            // check which mode is given
            if (!strcasecmp(argv[i + 1], "PREFIX")) {
                *mode = ParseMode::PREFIX;
                cout << "mode is PREFIX" << endl;
                i++;
            } else if (!strcasecmp(argv[i + 1], "INFIX")) {
                *mode = ParseMode::INFIX;
                cout << "mode is INFIX" << endl;
                i++;
            } else if (!strcasecmp(argv[i + 1], "POSTFIX")) {
                *mode = ParseMode::POSTFIX;
                cout << "mode is POSTFIX" << endl;
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

