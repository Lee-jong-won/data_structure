#include "expression_tree.h"

int main()
{
    expression_Tree tree;
    tree.to_postfix("3*(4+7)/12");
    tree.print();
}