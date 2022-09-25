#include "bst.h"
int main()
{
  
    CBST my_bst;
  
    my_bst.insert(40);
    my_bst.insert(70);
    my_bst.insert(34);
    my_bst.insert(80);
    my_bst.insert(90);

    my_bst.preorder();


    return 0; 
}