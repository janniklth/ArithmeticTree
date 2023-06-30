#include <string>
#include <vector>

#include "Num.hpp"
#include "Bracket.hpp"
#include "Op.hpp"
#include "string.h"
#include "math.h"


using namespace std;

class Tokenizer 
{
 
    string src;

public:
    // overloaded constructor
    Tokenizer(string s) 
	{
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht 
					   // über die String-Grenze zu laufen
    }

    // splits a string into tokens
    // return type is a vector of pointers to tokens
    vector<Token*>* tokenize() 
	{
        // vector that saves the single tokens as strings
        vector<string> stringVector;       //Testing purposes

        // given code from the exercise
        vector<Token*>* tokens = new vector<Token*>();
	    vector<Token*>::iterator i = tokens->begin();

        // length of the string for the loop
        int stringLength = src.length();


        // iterate over the string
        for (int i = 0; i < stringLength; i++){

            // check if the current char is a bracket
            if (src[i] == '(' || src[i] == ')' ){
                stringVector.push_back(src.substr(i, 1));       //Testing purposes

                // push a new Bracket object to the vector
                tokens->push_back(new Bracket(src[i]));
            }

            // check if the current char is an operator
            else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/') {
                stringVector.push_back(src.substr(i, 1));       //Testing purposes

                // push a new Op object to the vector
                tokens->push_back(new Op(src[i]));
            }

            // check if the current char is a number
            else if (src[i] <= '9' && src[i] >= '0'){

                int j = i;
                vector<char> numVector;

                // put all single digits of the number into a vector
                while (src[j] <= '9' && src[j] >= '0'){
                    numVector.push_back(src[j]);
                    j++;
                }

                int builtNumber = 0;

                // bult the number from the vector of single digits
                for (int k = 0; k < numVector.size(); k++){
                    int temp = numVector[k] - '0';
                    builtNumber += temp * pow(10, numVector.size() - k - 1);
                }

                // set counter i to the right value to continue the loop
                j = j-i;
                i += j-1;

                stringVector.push_back(to_string(builtNumber));       //Testing purposes

                // push a new Num object to the vector
                tokens->push_back(new Num(builtNumber));

            }
        }

        // print out vector tokens for testing purposes
        cout << "Testausgabe: " << endl;
        cout << "Einzelne Tokens: " << endl;
        for (int i = 0; i < stringVector.size(); i++){
            cout << stringVector[i] << "  //  ";
        }

        return tokens;
    }
    
};