#include "SAT.h"
#include <stack>
#include <iostream>
#include <string.h>

using std::stack;
using std::wcout;
using std::cout;

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
    /*infix의 n번째 요소를 precedence 자료형의 한 값으로 바꿔준다*/

    

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
    case L'￢':
        return precedence::NOT;
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
        case precedence::NOT:
           return L'￢';
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
    /*
    infix->postfix로 변환할때 고려사항

    1.cursor가 input을 순회하며, cursor가 operand를 가리키면 그 operand는 그대로 output 배열에 넣는다.
    2.cursor가 operator를 가리키면, operator는 우선순위가 높은 것이 먼저 output 배열에 들어간다.
    이때, 연산자들간의 우선순위가 비교되야하는데, 비교 방법으로 스택 자료구조를 이용한다.

    스택 자료구조에 데이터가 비어있을 경우->해당 operator output 배열에 넣기
    스택 자료구조에 데이터가 있을 경우->스택 내부 top 데이터의 우선순위와 cursor가 가리키는 연산자의 우선순위를 비교한다.

          (1).스택 내부 top 데이터의 우선순위가 높을 경우, top 데이터를 스택에서 제거
          (2).top이였던 데이터를 output 배열에 추가
          ->위 과정을 cursor가 가리키는 연산자의 우선순위가 커질때 까지 반복한다.
          (3)cursor가 가리키는 operator를 output 배열에 추가.

          //
          주의사항! (괄호가 처리되는 방식)

          괄호 안에 있는 연산자들은 괄호밖에 있는 연산자들에 비해 연산 우선순위가 높아야한다.
          따라서, '('의 괄호 안 우선순위는 연산자들중 가장 낮게, 괄호 밖 우선순위는 연산자들 중 가장 높게
          설정한다.

          이렇게 되면, 다음을 얻을 수 있다.
          1.cursor가 '('를 가리킬 때, 스택의 가장 위에 어떤 데이터가 있던지 상관없이 '('가
          스택에 삽입된다.
          2.'(' 가 스택에 삽입이 된 이후, '('이 스택의 가장 위가 되어, cursor가 가리키는 operator와 비교될 때,
          '('은 출력이 되지 않다가, 순회가 계속 진행되어 output에 데이터 계속 추가된다.
          3. cursor가 ')'를 만나면 '(' 이후 스택에 가지고 있던 operator를 차례로 output에 집어넣는다.
          3.결과적으로 output에는 괄호 안의 연산이 괄호 밖의 연산보다 우선시 된 식이 만들어진다.
          //

    */
    
    
    
    
    
    int n = 0;
    int index = 0;
    precedence token;
    stack<precedence> oper_stack;

    oper_stack.push(precedence::EOS);
    postfix = new wchar_t[wcslen(infix)];

    for (token = getToken(infix, &n); token != precedence::EOS; token = getToken(infix, &n))
    {
        if(token == precedence::OPERAND || token == precedence::NOT)
        {
            if(token == precedence::OPERAND)
            {
                size++;
            }

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

    leaf = (tNode**)malloc(size * sizeof(tNode*));

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

void SAT_problem::make_tree(const wchar_t* _postfix)
{
    /*
   
    
    cursor가 prefix로 표현된 문자열 데이터를 하나씩 읽으면서 다음의 연산을 수행한다

    a)cursor가 가리키는 문자를 저장하는 노드를 새로 만든다.
    
    b-1)cursor가 가리키는 문자가 연산자일 경우 -> 스택의 가장 위에서 데이터를 두개 뽑아서 각각 연산자 노드의 자식으로 삼는다.
    b-2)cursor가 가리키는 문자가 Not일 경우 -> 스택에 해당 노드의 주소를 집어넣는다.
    b-3)cursor가 가리키는 문자가 피연산자일 경우 -> 스택에 해당 노드의 주소를 집어넣되, 
    b-4)만약 스택의 가장 위쪽에 not이 저장된 노드가 있는 경우, not의 오른쪽 자식 노드로 해당 노드를 not 노드와 연결한다.    
    
    c)a에서 만든 노드의 주소를 스택에 집어넣는다.
    */
    


    int n = 0;
    int leaf_num = 0;
    stack<tNode*> tree_Node;

    to_postfix(_postfix);

    for( precedence cursor = getToken(postfix, &n); cursor != precedence::EOS; cursor = getToken(postfix, &n) )
    {
        tNode* new_node = new tNode(nullptr, nullptr, logical::TRUE, true);

        if(cursor == precedence::AND || cursor == precedence::OR)
        {
            if(cursor == precedence::AND)
            {
                new_node->data = logical::AND;
            }
            else 
            {
                new_node->data = logical::OR;
            }

            new_node->rightchild = tree_Node.top();
            tree_Node.pop();
            new_node->leftchild = tree_Node.top();
            tree_Node.pop();
        } 
        else if (cursor == precedence::NOT) 
        {
          if(tree_Node.empty())
          {
              tree_Node.push(new_node);
          }

          new_node->data = logical::NOT;
        }  
        else
        { 
            leaf[leaf_num] = new_node;
            leaf_num++;

            if(!tree_Node.empty())
            {
                if (tree_Node.top()->data == logical::NOT)
                {
                    tree_Node.top()->rightchild = new_node;
                    continue;
                }
            }
        }
    
        tree_Node.push(new_node);
    }

    root = tree_Node.top();
}

void SAT_problem::postOrderEval(tNode* treePointer)
{
    /*postOrdertravesal로 트리를 순회하면서, 조건에 따라 각 노드의 진리값 변수를 갱신한다*/





    if(treePointer)
    {
        postOrderEval(treePointer->leftchild);
        postOrderEval(treePointer->rightchild);
        switch(treePointer->data)
        {
            case logical::NOT:
            {
                treePointer->value = !(treePointer->rightchild->value);
                break;
            }
            case logical::AND:
            {
                treePointer->value = treePointer->rightchild->value && treePointer->leftchild->value;
                break;
            }
            case logical::OR:
            {
                treePointer->value = treePointer->rightchild->value || treePointer->leftchild->value;
                break;
            }
            case logical::TRUE:
            {
                treePointer->value = true;
                break;
            }
            case logical::FALSE:
            {
                treePointer->value = false;
                break;
            }
        }
    }
}

void inorder_print(tNode* root)
{
    if(root)
    {
        inorder_print(root->leftchild);
        if(root->value)
        {
            cout << "true" << " ";
        }
        else
        {
            cout << "false" << " ";
        }
        inorder_print(root->rightchild);
    }
}

void SAT_problem::print()
{
    inorder_print(root);
}