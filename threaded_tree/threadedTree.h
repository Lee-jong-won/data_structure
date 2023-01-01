#ifndef _threadedTree_h_
#define _threadedTree_h_ 

typedef struct threadedTree 
{
    bool leftThread;
    struct threadedTree* leftChild;
    char data;
    struct threadedTree* rightChild;
    bool rightThread;

    threadedTree(bool _leftThread, struct threadedTree* _leftChild, char _data, struct threadedTree* _rightChild, bool _rightThread)
    :
    leftThread(_leftThread),
    leftChild(_leftChild),
    data(_data),
    rightChild(_rightChild),
    rightThread(_rightThread)
    {}
} threadedTree;
typedef struct threadedTree* threadedPointer;

class threadTree
{
    private:
        threadedPointer root;
    
    public:
        threadTree()
            : root(nullptr)
            {}
    
    public:
        class iterator
        {
            private:
               threadTree* m_pTree;
               threadedPointer m_pData;

            public:
               iterator(threadTree* _pTree, threadedPointer _pData)
               : m_pTree(_pTree)
               , m_pData(_pData)
               {}
               ~iterator()
               {}
            
            public:
               iterator& operator ++();
               iterator operator ++(int);
        };

    public:
        iterator find_node(int search_data);
        iterator begin();
        void tinorder();
        void insertRight(iterator _iter, int _data);
        void insertLeft(iterator _iter, int _data);

}

#endif


