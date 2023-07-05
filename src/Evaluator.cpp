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
    // return = Wurzeltoken des Baumes (Operator)
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
    cout << "Tiefe:   " << e->depth(e) << endl;

    // Grafische Darstellung des arithmetischen Binärbaums
    Visualizer *v = new Visualizer(e, Visualizer::REGULAR); // Layout 1: gleiche Abstände zwischen Knoten
    //Visualizer v = new Visualizer(e, Visualizer::BINARY); // Layout 2: binäre Unterteilung

    cout << "Grafische Darstellung des Baumes:" << endl;
    v->printTree(e);

    // Text-/Grafikfenster sichtbar machen
    // ...

}


// private method to check if token is an operator
bool Evaluator::checkOperator(char i)
{
    return (i == '+' || i == '-' || i == '*' || i == '/' || i == '^');
}

// private method to call the corresponding parse method
Token *Evaluator::parse(vector<Token *> *tok, char mode)
{
    vector<Token *>::iterator i = tok->begin();
    switch (mode) {
        case '<':
            return parsePrefix(i);
        case '>':
            return parsePostfix(i);
        default :
            return parseInfix(i);
    }
}


// private method to parse prefix expression
Token *Evaluator::parsePrefix(vector<Token *>::iterator &i)
{
    // return leaf node without further recursion if token is a m_number
    if ((*i)->getTokenType() == TokenType::NUMBER)
    {
        return *i;
    }
    // else create new operator node and call parsePrefix recursively for the getLeft and right child of the operator
    else
    {
        Operator* operator_node = new Operator((*i)->getValue(), parsePrefix(++i), parsePrefix(++i));
        return operator_node;
    }
}


// private method to parse postfix expression
Token *Evaluator::parsePostfix(vector<Token *>::iterator i)
{
    stack<Token*> *s = new stack<Token*>();

    // loop that iterates through the vector of tokens
    do
    {
        // if the token is a m_number, push it to the stack
        if ((*i)->getTokenType() == TokenType::NUMBER)
        {
            s->push(*i);
        }

        // if the token is an operator, create a new operator-node with the two operands from the stack
        else
        {
            // take the two operands from the stack and delete them
            Token* tmp_operand_left = s->top(); s->pop();
            Token* tmp_operand_right = s->top(); s->pop();

            // push new operator-node to stack
            s->push(new Operator((*i)->getValue(), tmp_operand_left, tmp_operand_right));
        }

        i++; // iterate to next token
    } while (*i != nullptr); // loop until end of vector is reached

    // return root of the m_tree (top of the stack)
    return s->top();
}


// private method to parse infix expression
Token *Evaluator::parseInfix(vector<Token *>::iterator i)
{
    stack<Token*> *s = new stack<Token*>();

    // loop that iterates through the vector of tokens
    do
    {
        // compare two


        // if token is not a closing bracket, push it to the stack
        if ( (*i)->getValue() != ")" )
        {
            s->push(*i);
        }
        else
        {
            Token* tmp_operand_right = s->top(); s->pop();
            Token* tmp_operator = s->top(); s->pop();
            Token* tmp_operand_left = s->top(); s->pop();

            // delete opening bracket that is getLeft on the stack
            s->pop();

            // push new operator-node to stack
            s->push(new Operator(tmp_operator->getValue(), tmp_operand_left, tmp_operand_right));
        }
        i++; // iterate to next token
    } while (*i != nullptr); // loop until end of vector is reached

    // return root of the m_tree (top of the stack)
    return s->top();
}
