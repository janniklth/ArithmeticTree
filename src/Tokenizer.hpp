#include <string>
#include <vector>

#include "Num.hpp"
#include "Bracket.hpp"
#include "Op.hpp"
#include "string.h"


using namespace std;

class Tokenizer 
{
 
    string src;

public:
    Tokenizer(string s) 
	{
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht 
					   // über die String-Grenze zu laufen
    }
    
    vector<Token*>* tokenize() 
	{
        vector<Token*>* tokens = new vector<Token*>();
	    vector<Token*>::iterator i = tokens->begin();

        int stringLength = src.length();

        vector<string> stringVector;       //Testing purposes

        // iterate over the string
        for (int i = 0; i < stringLength; i++){

            // check if the current char is a bracket
            if (src[i] == '(' || src[i] == ')' ){
                stringVector.push_back(src.substr(i, 1));       //Testing purposes
                tokens->push_back(new Bracket(src[i]));
            }

            // check if the current char is an operator
            else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/') {
                stringVector.push_back(src.substr(i, 1));       //Testing purposes
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

                // generate a new Num object and add it to the vector
                stringVector.push_back(to_string(builtNumber));       //Testing purposes
                tokens->push_back(new Num(builtNumber));

                // set counter i to the right value to continue the loop
                j = j-i;
                i += j-1;
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