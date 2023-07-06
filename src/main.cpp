#include <iostream>
#include "Evaluator.hpp"

using namespace std;


// static var to count the nodes
static int node_counter;


int main(int argc, char* argv[])
{
    string input = " ";

    string infix = "((10 + 20) * 30)";
    string infix2 = "( ( (2 + 2) + (2 + 2) ) * ( (10 / 5) * 3) )";
    string postfix = "10 20 + 30 *";
    string prefix = "+ 10 20";

    if (argc > 1) input = argv[1];
    for (int i = 1; i < argc; i++)
    {
        input += " ";
        input += argv[i];
    }
    if (input.length() == 0)
        cout << "Arguments needed!" << endl;
    else
    {
        char mode = argv[1][0];
        if (mode == '<' || mode == '|' || mode == '>')
            input = input.substr(1);
        else
            mode = '|'; // Standard: Infix
        Evaluator e;
        e.evaluate(input, mode);
    }


    //Tokenizer *t = new Tokenizer(exp);
    //e.evaluate(prefix, '<');
    //e.evaluate(infix2, '|');
    //e.evaluate(postfix, '>');

    return 0;
}
