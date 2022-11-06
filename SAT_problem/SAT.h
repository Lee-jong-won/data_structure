#include <vector>

using std::vector;

enum class precedence 
{
    LPAREN,
    RPAREN,
    AND,
    OR,
    NOT,
    EOS,
    OPERAND
};

enum class logical
{
    NOT,
    AND,
    OR,
    TRUE,
    FALSE
};

typedef struct node {
    struct node* leftchild;
    struct node* rightchild;
    logical data;
    bool value;

    node(struct node *lchild, struct node *rchild, logical _data, bool _value)
        : leftchild(lchild), rightchild(rchild), data(_data), value(_value) {}
} tNode;

class SAT_problem
{
    private:
       int* isp;
       int* icp;
       wchar_t* postfix;
    
    public:
       vector<tNode*> leaf;
       tNode* root;

    private:
       wchar_t change_format(precedence);
       precedence getToken(const wchar_t*, int*);
       void to_postfix(const wchar_t*);
    
    public:
       SAT_problem();
       ~SAT_problem();
    
    public:
       void make_tree(const wchar_t *);
       void postOrderEval(tNode*);
       void print();

};