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

void CBST::inorder()
{
    tBSTNode* cursor = root;
    stack<tBSTNode*> my_stack;

    while(cursor)
    {
        my_stack.push(cursor);
        cursor = cursor->arrNode[(int)NODE_TYPE::LCHILD];
    }

    while(true)
    {
        if(!my_stack.empty())
        {
            cursor = my_stack.top();
            my_stack.pop();
            cout << cursor->data << " ";

            if(cursor->arrNode[(int)NODE_TYPE::RCHILD])
            {
                cursor = cursor->arrNode[(int)NODE_TYPE::RCHILD];

                while(cursor)
                {
                    my_stack.push(cursor);
                    cursor = cursor->arrNode[(int)NODE_TYPE::LCHILD];
                }
            }
            
        }
        else
        {
            break;
        }
        
    }
}

void CBST::postorder()
{
    tBSTNode* cursor = root;
    tBSTNode* prev_cursor = nullptr;
    stack<tBSTNode*> my_stack;
    
    while(cursor)
    {
        my_stack.push(cursor);
        cursor = cursor->arrNode[(int)NODE_TYPE::LCHILD];
    }
    cursor = my_stack.top();

    while (true)
    {
        if (!my_stack.empty())
        {
            // 오른쪽 자식이 없는 경우
            if (!cursor->arrNode[(int)NODE_TYPE::RCHILD])
            {
                cout << cursor->data << " ";
                my_stack.pop();
                prev_cursor = cursor;

                if (!my_stack.empty())
                {
                    cursor = my_stack.top();
                }
            }
            // 오른쪽 자식이 있는 경우
            else
            {
                if(prev_cursor != cursor->arrNode[(int)NODE_TYPE::RCHILD])
                {
                    cursor = cursor->arrNode[(int)NODE_TYPE::RCHILD];

                    while (cursor)
                    {
                        my_stack.push(cursor);
                        cursor = cursor->arrNode[(int)NODE_TYPE::LCHILD];
                    }
                    
                    cursor = my_stack.top();
                }
                else
                {
                    cout << cursor->data << " ";
                    my_stack.pop();
                    prev_cursor = cursor;

                    if(!my_stack.empty())
                    {
                        cursor = my_stack.top();
                    }
                }
                
            }
            
        }
        else
        {
            break;
        }
        
    }
}