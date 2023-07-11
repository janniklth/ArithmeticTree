/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#include "Evaluator.hpp"
#include "Utilities.hpp"
#include "../lib/BST_Visualizer.hpp"

// public method to evaluate the expression
void Evaluator::evaluate(string exp, Utilities::ParseMode mode)
{
    // String in Tokens zerlegen
    Tokenizer *t = new Tokenizer(exp);

    // Aus den Tokens den arithmetischen Binärbaum aufbauen
    // return = Wurzeltoken des Baumes (Operator)
    Token *e = parse(t->tokenize(), mode);

    // output of the expression and its evaluation
    cout << "Prefix:  " << e->prefix() << " = " << e->eval() << endl;
    cout << "Infix:   " << e->infix() << " = " << e->eval() << endl;
    cout << "Postfix: " << e->postfix() << " = " << e->eval() << endl;
    cout << "#Knoten: " << e->nodes() << endl;
    cout << "Tiefe:   " << e->depth(e) << endl;


    // graphical representation of the tree
    cout << "\nVisualization by ourself:" << endl;
    Visualizer::printSimpleTree(e);

    // test implementation of bst visualization
    cout << "\n\nVisualization by https://github.com/YoussefRaafatNasry/bst-ascii-visualization:\n" << endl;
    BST_Visualizer* bst_visualizer = new BST_Visualizer(e);
    bst_visualizer->visualize();
}


// private method to check if token is an operator
bool Evaluator::checkOperator(char i)
{
    return (i == '+' || i == '-' || i == '*' || i == '/' || i == '^');
}

// private method to call the corresponding parse method
Token *Evaluator::parse(vector<Token *> *tok, Utilities::ParseMode mode)
{
    vector<Token *>::iterator i = tok->begin();
    switch (mode) {
        case Utilities::ParseMode::PREFIX:
            return parsePrefix(i);
        case Utilities::ParseMode::POSTFIX:
            return parsePostfix(i);
        case Utilities::ParseMode::INFIX:
            return parseInfix(i);
        default :
            cout << "Error: Invalid ParseMode" << endl;
            return parseInfix(i);
    }
}


// private method to parse prefix expression
Token *Evaluator::parsePrefix(vector<Token *>::iterator &i)
{
    // return leaf node without further recursion if token is a m_number
    if ((*i)->getTokenType() == TokenTypeABC::NUMBER)
    {
        return *i;
    }
    // else create new operator node and call parsePrefix recursively for the getLeft and m_right child of the operator
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
        if ((*i)->getTokenType() == TokenTypeABC::NUMBER)
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
