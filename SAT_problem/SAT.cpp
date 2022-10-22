#include "SAT.h"
#include <stack>
#include <iostream>
#include <string.h>

using std::stack;

SAT_problem::SAT_problem()
{
    isp = new int[5];
    icp = new int[5];

    /*lparen,rparen,and,or,eos */
    int _isp[5] = {0,19,12,12,0};
    int _icp[5] = {20,19,12,12,0};

    for(int i = 0; i < 5; i++)
    {
        isp[i] = _isp[i];
        icp[i] = _icp[i];
    }
}

SAT_problem::~SAT_problem()
{
}

precedence SAT_problem::getToken(const wchar_t *infix, int *n)
{
    wchar_t symbol = infix[(*n)++];
    switch (symbol)
    {
    case L'(':
        return precedence::LPAREN;

    case L')':
        return precedence::RPAREN;

    case L'∧':
        return precedence::AND;

    case L'∨':
        return precedence::OR;
    case L'\0' :
        return precedence::EOS;
    default:
        return precedence::OPERAND;
    }
}

wchar_t SAT_problem::change_format(precedence object)
{
    switch(object)
    {
        case precedence::AND:
           return L'∧';
        case precedence::OR:
           return L'∨';
        case precedence::LPAREN:
           return L'(';
        case precedence::RPAREN:
           return L')';
        case precedence::EOS:
           return L'\0';
        default:
           return L'n';
    }

}

void SAT_problem::to_postfix(const wchar_t* infix)
{
    int n = 0;
    int index = 0;
    precedence token;
    stack<precedence> oper_stack;

    oper_stack.push(precedence::EOS);
    postfix = new wchar_t[wcslen(infix)];

    for (token = getToken(infix, &n); token != precedence::EOS; token = getToken(infix, &n))
    {
        if(token == precedence::OPERAND)
        {
            postfix[index] = infix[n-1];
            index++;
        }
        else if(token == precedence::RPAREN)
        {
            while(oper_stack.top() != precedence::LPAREN)
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
    while(token != precedence::EOS)
    {
        postfix[index] = change_format(token);
        index++;
        oper_stack.pop();
        token = oper_stack.top();
    }
    postfix[index] = L'\0';

}