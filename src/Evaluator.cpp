//
// Created by Jannik Loth on 04.07.23.
//

#include "Evaluator.hpp"

// public method to evaluate the expression
void Evaluator::evaluate(string exp, char mode)
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


// private method to check if token is an operator
bool Evaluator::checkOperator(char i)
{
    if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^'){
        return true;
    }
    else {
        return false;
    }
}


// private method to call the corresponding parse method
Token *Evaluator::parse(vector<Token *> *tok, char mode)
{
    vector<Token*>::iterator i = tok->begin();
    switch (mode)
    {
        case '<': return parsePrefix(i);
        case '>': return parsePostfix(i);
        default : return parseInfix(i);
    }
}


// private method to parse prefix expression
Token *Evaluator::parsePrefix(vector<Token *>::iterator &i)
{
    if ( !(checkOperator((*i)->getType()) ) )
    {
        return *i;
    }
    else
    {
        Operator* OpNode = new Operator((*i)->getType(), parsePrefix(++i), parsePrefix(++i));
        return OpNode;
    }
}


// private method to parse postfix expression
Token *Evaluator::parsePostfix(vector<Token *>::iterator i)
{
    stack<Token*> *s = new stack<Token*>();

    // loop that iterates through the vector of tokens
    do
    {
        // wenn der token eine Zahl ist - auf stack
        if ((*i)->getType() == 'n')
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


// private method to parse infix expression
Token *Evaluator::parseInfix(vector<Token *>::iterator i)
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
