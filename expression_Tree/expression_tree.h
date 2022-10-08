enum class precedence
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
};

typedef struct tNode
{
    char data;
    struct tNode* left_child;
    struct tNode* right_child;

    tNode(precedence _data, tNode* left_ptr, tNode* right_ptr)
    : data(_data),
      left_child(left_ptr),
      right_child(right_ptr)
    {

    }
}tNode;

class expression_Tree{
    
    private:
       tNode* root;
       int* isp;
       int* icp;
       char* postfix;

    private:
       char change_format(precedence object);
       precedence getToken(const char *infix, int *n);
       void to_postfix(const char *infix);
    
    public:
       expression_Tree();
       ~expression_Tree();
    
    public:
       void make_tree(const char *infix);
       void print();
};