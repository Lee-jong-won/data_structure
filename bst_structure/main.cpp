#include "bst.h"
int main()
{
  
    CBST my_bst;
  
    my_bst.insert(80);
    my_bst.insert(60);
    my_bst.insert(90);
    my_bst.insert(45);
    my_bst.insert(70);
    my_bst.insert(85);
    my_bst.insert(100);

    my_bst.inorder();


    return 0; 
}