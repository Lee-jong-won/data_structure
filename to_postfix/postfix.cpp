#include "postfix.h"
#include <stack>
#include <string.h>

using std::stack;

/*isp and icp arrays -- index is value of precedence 
lparen, rapren, plus, minus, times, divide, mod, eos*/
int isp[] = {0,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};

char change_format(precedence object)
{
    switch(object)
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
        default :
             return 'n';      
    }
}

precedence getToken(const char *infix, int *n)
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

void postfix(const char *infix, char *postfix)
{
    /*
    infix->postfix로 변환할때 고려사항

    1.input을 순회하며, operand는 그대로 output 배열에 넣는다.
    2.operator는 우선순위가 높은 것이 먼저 output 배열에 들어간다.
    이때, 연산자들간의 우선순위가 비교되야하는데, 비교 방법으로 스택 자료구조를 이용한다.
    
    스택 자료구조에 데이터가 비어있을 경우->해당 연산자 output 배열에 넣기
    스택 자료구조에 데이터가 있을 경우->스택 내부 top 데이터의 우선순위와 해당 연산자의 우선순위를 비교한다.

          (1).스택 내부 top 데이터의 우선순위가 높을 경우, top 데이터를 스택에서 제거
          (2).top이였던 데이터를 output 배열에 추가
          ->위 과정을 해당 연산자의 우선순위가 커질때 까지 반복한다.
          
          주의사항! (괄호를 처리하는 법)
          괄호 안에 있는 연산자들은 괄호밖에 있는 연산자들에 비해 연산 우선순위가 높아야한다.
          따라서, 
      
    */

    int n = 0;
    int index = 0;
    precedence token;
    stack<precedence> oper_stack;
    oper_stack.push(precedence::eos);

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
                    postfix[index] = infix[n-1];
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