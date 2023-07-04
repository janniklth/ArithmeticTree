#include <iostream>
#include "Evaluator.hpp"

using namespace std;

int main(int argc, char* argv[])
{

    string infix = "((10 + 20) * 30)";
    string postfix = "10 20 + 30 *";
    string prefix = "* + 10 20 30";
    // Knoten: 5
    // Tiefe: 3


    //Tokenizer *t = new Tokenizer(exp);
    Evaluator e;

    //e.evaluate(prefix, '<');
    e.evaluate(infix, '|');
    //e.evaluate(postfix, '>');

    //t->tokenize();

    return 0;
}
