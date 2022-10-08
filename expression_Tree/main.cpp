#include "expression_tree.h"

int main()
{
    expression_Tree tree;
    
    tree.make_tree("(A+B)*C-(D-E)*(F+G)");
    tree.print();
}