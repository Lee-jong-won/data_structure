//main.cpp

#include "binary_tree.h"
#include "stdlib.h"

int main()
{
    node_ptr root = (node_ptr)malloc(sizeof(node_ptr));
    root->data = 100;
    root->leftChild = nullptr;
    root->rightChild = nullptr;

    node_ptr search_addr = nullptr;
    find_node(root, &search_addr, 100);
    if(search_addr != nullptr)
    {
        insertLeft(search_addr, 50);
    }

    search_addr = nullptr;
    find_node(root, &search_addr, 50);
    if(search_addr != nullptr)
    {
        insertRight(search_addr, 60);
    }

    search_addr = nullptr;
    find_node(root, &search_addr, 50);
    if(search_addr != nullptr)
    {
        insertLeft(search_addr, 70);
    }
    
    search_addr = nullptr;
    find_node(root, &search_addr, 100);
    if(search_addr != nullptr)
    {
        insertLeft(search_addr, 30);
    }

    search_addr = nullptr;
    find_node(root, &search_addr, 100);
    if(search_addr != nullptr)
    {
        insertRight(search_addr, 80);
    }

    inorder(root);

    return 0;
}