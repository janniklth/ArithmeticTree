#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>

#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Visualizer.hpp"
#include "Number.hpp"

using namespace std;

/*
 * Auswertung von arithmetischen Baeumen
 */
class Evaluator 
{

public:
	/*
     * Wertet einen arithmetischen Ausdruck aus. Dazu wird der Ausdruck erst in Tokens zerlegt.
     * Diese werden dann in einen arithmetischen Binärbaum umgewandelt, der dann ausgewertet und 
	 * grafisch dargestellt werden kann.
     *
     * Parameter: exp der arithmetische Ausdruck
     * Parameter: mode: '<': Prefix, '|': Infix, '>': Postfix
     */
    void evaluate(string exp, char mode)
	{

        // String in Tokens zerlegen
        Tokenizer *t = new Tokenizer(exp);

        // Aus den Tokens den arithmetischen Binärbaum aufbauen
        Token *e = parse(t->tokenize(), mode);

        // Testbaum, falls Tokenizer und/oder Parser noch nicht fertig:
        /*
        e = new Operator('+',
                   new Operator('*',
                          new Number(2),
                          new Number(3)),
                   new Operator('-',
                          new Operator('/',
                                 new Number(6),
                                 new Number(2)),
                          new Number(1)));
       */
       // Prefix:  + * 2 3 - / 6 2 1 = 8
       // Infix:   ((2 * 3) + ((6 / 2) - 1)) = 8
       // Postfix: 2 3 * 6 2 / 1 - + = 8
       // #Knoten: 9
       // Tiefe:   4

        // Ausgabe des arithmetischen Ausdrucks
        cout << "Prefix:  " << e->prefix() << " = " << e->eval() << endl;
        cout << "Infix:   " << e->infix() << " = " << e->eval() << endl;
        cout << "Postfix: " << e->postfix() << " = " << e->eval() << endl;
        cout << "#Knoten: " << e->nodes() << endl;
        cout << "Tiefe:   " << e->depth() << endl;

        // Grafische Darstellung des arithmetischen Binärbaums
		Visualizer *v = new Visualizer(e, Visualizer::REGULAR); // Layout 1: gleiche Abstände zwischen Knoten
        //Visualizer v = new Visualizer(e, Visualizer::BINARY); // Layout 2: binäre Unterteilung

		// Text-/Grafikfenster sichtbar machen
		// ...

    }

private:
    bool checkOperator(char i){
        if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^'){
            return true;
        }
        else {
            return false;
        }
    }

	/*
     * Ruft die entsprechende Parse-Methode (Prefix, Infix oder Postfix) auf.
     *
     * Parameter: tok der tokenisierte arithmetische Ausdruck
     * Parameter: mode '<': Prefix, '|': Infix, '>': Postfix
     * Return:: der arithmetische Binärbaum
     */
	Token* parse(vector<Token*> *tok, char mode) 
	{
		vector<Token*>::iterator i = tok->begin();
		switch (mode) 
		{
            case '<': return parsePrefix(i);
            case '>': return parsePostfix(i);
            default : return parseInfix(i);
        }
    }

	Token* parsePrefix(vector<Token*>::iterator i) 
	{

        // to implement ...

        cout << "Die Methode Evaluator.parsePrefix ist noch nicht implementiert!" << endl;

        return new Number(); // remove this line
    }

    Token* parsePostfix(vector<Token*>::iterator i)
	{
		stack<Token*> *s = new stack<Token*>();

        // loop that iterates through the vector of tokens
        do
        {
            // wenn der token eine Zahl ist - auf stack
            if ( !(checkOperator( (*i)->getType()) ) )
            {
                s->push(*i);
            }

            // wenn der token ein Operator ist - beide Operanden vom Stapel nehmen und Operator erzeugen
            else
            {
                // take 2 operands from stack (right operand first)
                Token* tmpOperand_right = s->top(); s->pop();
                Token* tmpOperand_left = s->top(); s->pop();

                // create new operator-node with the 3 tokens (left operand, operator, right operand)
                Operator* OpNode = new Operator((*i)->getType(), tmpOperand_left, tmpOperand_right);

                // push new operator-node to stack
                s->push(OpNode);
            }

           i++; // iterate to next token
        } while (*i != nullptr); // loop until end of vector is reached


		// return root of the tree (top of the stack)
		return s->top();
    }

    // Parses infix expression to an expression tree
    // return type is the root node of the tree (top of the stack)
    Token* parseInfix(vector<Token*>::iterator i)
	{
        stack<Token*> *s = new stack<Token*>();

        // loop that iterates through the vector of tokens
        do
        {
            // if token is not a closing bracket, push it to the stack
            if ( (*i)->getType() != ')' )
            {
                s->push(*i);
            }
            else
            {

                Token* tmpOperand_right = s->top(); s->pop();
                Token* tmpOperator = s->top(); s->pop();
                Token* tmpOperand_left = s->top(); s->pop();

                // delete opening bracket that is left on the stack
                s->pop();

                // create new operator-node with the 3 tokens (left operand, operator, right operand)
                Operator* OpNode = new Operator(tmpOperator->getType(), tmpOperand_left, tmpOperand_right);

                // push new operator-node to stack
                s->push(OpNode);
            }

            i++; // iterate to next token
        } while (*i != nullptr); // loop until end of vector is reached


        // return root of the tree (top of the stack)
        return s->top();
    }

};

