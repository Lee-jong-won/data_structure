#ifndef _threadedTree_h_
#define _threadedTree_h_ 

typdef struct threadedTree 
{
    bool leftThread;
    struct threadedTree* leftChild;
    char data;
    struct threadedTree* rightChild;
    bool rightThread;
} threadedTree;
typdef struct threadedTree *threadedPointer;

class threadTree
{
    private:
        threaded
    
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
               iterator& operator --();
               iterator operator --(int);
        };

    public:
        iterator find_node(int search_data);
        iterator begin();
        iterator end();
        void tinorder();
        void insertRight(iterator _iter, int _data);
        void insertLeft(iterator _iter, int _data);

}

#endif


