#include <iostream>
#include "Evaluator.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    //std::cout << "Hello, World!" << std::endl;

    string exp = "((10 + 20) * 30)";

    Tokenizer *t = new Tokenizer(exp);

    t->tokenize();

    return 0;
}
