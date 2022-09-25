#include "bst.h"
#include <stdio.h>

int main()
{
    tree my_tree;

    new_tree(&my_tree, 8);

    insert(&my_tree, 30);
    insert(&my_tree, 27);
    insert(&my_tree, 31);
    insert(&my_tree, 25);
    insert(&my_tree, 28);
    insert(&my_tree, 35);
    insert(&my_tree, 34);

    for(int i = 0; i < my_tree.max_Size; i++)
    {
        if(my_tree.data[i] != -1)
        {
            printf("index:%d, data:%d\n", i, my_tree.data[i]);
        }
    }

    printf("\n\n\n");
    printf("delete 31:\n");
    tree_delete(&my_tree, 31);

    for(int i = 0; i < my_tree.max_Size; i++)
    {
        if(my_tree.data[i] != -1)
        {
            printf("index:%d, data:%d\n", i, my_tree.data[i]);
        }
    }

    printf("\n\n\n");
    printf("delete 35:\n");
    tree_delete(&my_tree, 35);

    for(int i = 0; i < my_tree.max_Size; i++)
    {
        if(my_tree.data[i] != -1)
        {
            printf("index:%d, data:%d\n", i, my_tree.data[i]);
        }
    }

    printf("\n\n\n");
    printf("delete 30:\n");
    tree_delete(&my_tree, 30);

    for(int i = 0; i < my_tree.max_Size; i++)
    {
        if(my_tree.data[i] != -1)
        {
            printf("index:%d, data:%d\n", i, my_tree.data[i]);
        }
    }




    return 0;
}