#include <iostream>
#include "Evaluator.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    string exp = "((10 + 20) * 30)";

    Tokenizer *t = new Tokenizer(exp);

    t->tokenize();

    return 0;
}
