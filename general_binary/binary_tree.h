//binary_Tree.h
typedef struct binary_node {
    int data;
    binary_node* leftChild;
    binary_node* rightChild;
};

typedef struct binary_node* node_ptr;

void insertRight(node_ptr s, int _data);
void insertLeft(node_ptr s, int _data);
void find_node(node_ptr root, node_ptr* search_addr, int search_data);
void inorder(node_ptr root);