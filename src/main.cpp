#include <iostream>
#include "Evaluator.hpp"

using namespace std;

int main(int argc, char* argv[])
{

    for(int i = 1; i < 1000000; i*=10)
    {
        cout << "i=" << i << "  log10=" << log10(i) << endl;
    }

    string exp = "((10 + 20) * 30)";

    Tokenizer *t = new Tokenizer(exp);

    t->tokenize();

    return 0;
}
