#include "threadedTree.h"

threadedTree::iterator& threadTree::iterator::operator++()
{
    /*find the inorder succesor of tree in a threaded binary tree and return the iterator*/
    threadedPointer temp;
    temp = this->m_pData;
    if(!this->m_pData->rightThread)
    {
        while(!temp->leftThread)
        {
            temp = temp->leftChild;
        }
    }

    this->m_pData = temp;

    return *this;
}

threadedTree::iterator threadTree::iterator::operator++(int)
{
    /*find the inorder succesor of tree in a threaded binary tree and return the iterator*/
    threadedPointer temp;
    temp = this->m_pData;
    if(!this->m_pData->rightThread)
    {
        while(!temp->leftThread)
        {
            temp = temp->leftChild;
        }
    }

    this->m_pData = temp;
    return iterator(this, this->m_pData);
}


