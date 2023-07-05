#include <iostream>
#include "Evaluator.hpp"

using namespace std;

int main(int argc, char* argv[])
{


    string infix = "((10 + 20) * 30)";
    string infix2 = "( ( (2 + 2) + (2 + 2) ) * ( (10 / 5) * 3) )";
    string postfix = "10 20 + 30 *";
    string prefix = "+ 10 20";
    // Knoten: 5
    // Tiefe: 3


    //Tokenizer *t = new Tokenizer(exp);
    Evaluator e;

    //e.evaluate(prefix, '<');
    e.evaluate(infix2, '|');
    //e.evaluate(postfix, '>');

    return 0;
}
