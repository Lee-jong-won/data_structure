#include "bst.h"
#include <iostream>
#include <stack>

using std::stack;
using std::cout;

bool CBST::insert(int _data)
{
    tBSTNode* pNewNode = new tBSTNode(_data, nullptr, nullptr);

    if(nullptr == root)
    {
        root = pNewNode;
    }
    else
    {
        tBSTNode* pNode = root;
        NODE_TYPE node_type = NODE_TYPE::END;

        while(true)
        {
            if(pNode->data < pNewNode->data)
            {
                node_type = NODE_TYPE::RCHILD;
            }
            else if(pNode->data > pNewNode->data)
            {
                node_type = NODE_TYPE::LCHILD;
            }
            else
            {
                return false;
            }

            if(nullptr == pNode->arrNode[(int)node_type])
            {
                pNode->arrNode[(int)node_type] = pNewNode;
                break;
            }
            else
            {
                pNode = pNode->arrNode[(int)node_type];
            }
               
        }
    }

    ++m_iCount;
    return true;    
}

void CBST::preorder()
{    
    tBSTNode* cursor = root;
    stack<tBSTNode*> my_stack;

    while(true)
    {
        cout << cursor->data << " ";
        
        if(cursor->arrNode[(int)NODE_TYPE::RCHILD])
        {
            my_stack.push(cursor->arrNode[(int)NODE_TYPE::RCHILD]);
        }
        if(cursor->arrNode[(int)NODE_TYPE::LCHILD])
        {
            my_stack.push(cursor->arrNode[(int)NODE_TYPE::LCHILD]);
        }

        if (!my_stack.empty())
        {
            cursor = my_stack.top();
        }
        else
        {
            break;
        }
        
        if(cursor != root)
        {
            my_stack.pop();
        }
        
    }


}