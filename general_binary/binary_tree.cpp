#include "binary_tree.h"
#include "assert.h"
#include "stdlib.h"
#include "stdio.h"

void inorder(node_ptr root)
{
    if(root)
    {
        inorder(root->leftChild);
        printf("%d", root->data);
        inorder(root->rightChild);
    }
}

void insertRight(node_ptr s, int _data)
{
    if(s == nullptr)
    {
        assert(nullptr);
    }

    node_ptr new_node = (node_ptr)malloc(sizeof(binary_node));
    new_node->data = _data;
    new_node->leftChild = nullptr;
    new_node->rightChild = nullptr;

    if(s->rightChild == nullptr)
    {
        s->rightChild = new_node;
    }
    else
    {
        node_ptr temp = s->rightChild;
        s->rightChild = new_node;
        new_node->rightChild = temp;
    }
    
}
void insertLeft(node_ptr s, int _data)
{
    if(s == nullptr)
    {
        assert(nullptr);
    }

    node_ptr new_node = (node_ptr)malloc(sizeof(binary_node));
    new_node->data = _data;
    new_node->leftChild = nullptr;
    new_node->rightChild = nullptr;

    if(s->leftChild == nullptr)
    {
        s->leftChild = new_node;
    }
    else
    {
        node_ptr temp = s->leftChild;
        s->leftChild = new_node;
        new_node->leftChild = temp;
    }
}

void find_node(node_ptr root, node_ptr* search_addr, int search_data)
{
    if(root)
    {
        if(root->data == search_data)
        {
            *search_addr = root;
        }
        find_node(root->leftChild, search_addr, search_data);
        find_node(root->rightChild, search_addr, search_data);
    }
}