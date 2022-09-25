enum class NODE_TYPE
{
    LCHILD, //0
    RCHILD, //1
    END, //2
};

typedef struct tBSTNode
{
    int data;
    tBSTNode* arrNode[(int)NODE_TYPE::END];

    tBSTNode(int _data, tBSTNode* _lptr, tBSTNode* _rptr)
    : data(_data)
    {
        arrNode[(int)NODE_TYPE::LCHILD] = _lptr;
        arrNode[(int)NODE_TYPE::RCHILD] = _rptr;
    }

}tBSTNode;

class CBST
{
    public:
      tBSTNode* root;
      int m_iCount;

    public:
      CBST()
         : root(nullptr),
           m_iCount(0)
      {
      }
    
    public:
       bool insert(int _data);
       void preorder();
       void inorder();
       void postorder();
};