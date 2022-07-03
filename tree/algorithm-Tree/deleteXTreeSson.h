#include "../linearQueue.h"

/*
算法：删去值为x的结点的子树
 */

void deleteXTreeSon(linkT &T, int key)
{
    if (T == NULL)
        return;
    if (T->data == key)
    {
        T->lChild = NULL;
        T->rChild = NULL;
    }
    else
    {
        deleteXTreeSon(T->lChild, key);
        deleteXTreeSon(T->rChild, key);
    }
}