//bst.h

typedef struct tree
{
    int* data;
    int max_Size;
    int _Count;
}tree;

void new_tree(tree* tree_Pointer, int _max_Size);
void insert(tree* tree_Pointer ,int _data);
void tree_expansion(tree* tree_Pointer, int* object);
int find(tree* tree_Pointer, int item);
void delete(tree* tree_Pointer, int item);
int check_child(tree* tree_Pointer, int index);
int is_Left_Child(tree* tree_Pointer, int index);
int is_Right_Child(tree* tree_Pointer, int index);