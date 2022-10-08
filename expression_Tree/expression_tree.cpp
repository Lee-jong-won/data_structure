#include "expression_tree.h"
#include <stack>
#include <stdio.h>
#include <string.h>

using std::stack;

expression_Tree::expression_Tree()
{
    isp = new int[8];
    icp = new int[8];

    int input1[8] = {0,19,12,12,13,13,13,0};
    int input2[8] = {20,19,12,12,13,13,13,0};

    for(int i = 0; i < 8; i++)
    {
        isp[i] = input1[i];
        icp[i] = input2[i];
    }
}

expression_Tree::~expression_Tree()
{
}


char expression_Tree::change_format(precedence object)
{
    switch (object)
    {
    case precedence::lparen:
        return '(';
    case precedence::rparen:
        return ')';
    case precedence::plus:
        return '+';
    case precedence::minus:
        return '-';
    case precedence::times:
        return '*';
    case precedence::divide:
        return '/';
    case precedence::mod:
        return '%';
    case precedence::eos:
        return '\0';
    default:
        return 'n';
    }
}

precedence expression_Tree::getToken(const char *infix, int *n)
{
    char symbol = infix[(*n)++];
    switch (symbol)
    {
    case '(':
        return precedence::lparen;

    case ')':
        return precedence::rparen;

    case '+':
        return precedence::plus;

    case '-':
        return precedence::minus;

    case '/':
        return precedence::divide;

    case '*':
        return precedence::times;

    case '%':
        return precedence::mod;

    case '\0' :
        return precedence::eos;

    default:
        return precedence::operand;
    }
}

void expression_Tree::to_postfix(const char *infix)
{
    int n = 0;
    int index = 0;
    precedence token;
    stack<precedence> oper_stack;
    oper_stack.push(precedence::eos);

    postfix = new char[strlen(infix)];

    for (token = getToken(infix, &n); token != precedence::eos; token = getToken(infix, &n))
    {
        if(token == precedence::operand)
        {
            postfix[index] = infix[n-1];
            index++;
        }
        else if(token == precedence::rparen)
        {
            while(oper_stack.top() != precedence::lparen)
            {
                postfix[index] = change_format(oper_stack.top());
                oper_stack.pop();
                index++;
            }
            oper_stack.pop();
        }
        else
        {
            if(!oper_stack.empty())
            {
                while(isp[(int)oper_stack.top()] >= icp[(int)token])
                {
                    postfix[index] = change_format(oper_stack.top());
                    oper_stack.pop();
                    index++;
                }
            }
            oper_stack.push(token);
        }
        
    }

    token = oper_stack.top();
    precedence temp;
    while(token != precedence::eos)
    {
        postfix[index] = change_format(token);
        index++;
        oper_stack.pop();
        token = oper_stack.top();
    }
    postfix[index] = '\0';

} 

void expression_Tree::make_tree(const char* infix)
{
    precedence cursor;
    to_postfix(infix);
    int n = 0;
    stack<tNode*> tree_stack;

    cursor = getToken(postfix, n);

    while( cursor != '\0' )
    {
        tNode* new_node = new tNode(postfix[n-1], nullptr, nullptr);
        if(cursor == precedence::operand)
        {
            tree_stack.push(new_node);
        }
        else
        {
            new_node->right_child = tree_stack.top();
            tree_stack.pop();
            new_node->left_child = tree_stack.top();
            tree_stack.pop();
            tree_stack.push(new_node);
        }

        cursor = getToken(postfix, n);
    }






}