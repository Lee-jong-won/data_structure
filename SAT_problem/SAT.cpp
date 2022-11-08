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