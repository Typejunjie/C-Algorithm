#include "../linearQueue.h"

/*
算法：打印值为x的元素的所有祖先
 */

int LogXancestors(linkT &T, int key)
{
    if (T == NULL)
        return 0;
    if (T->data == key)
        return 1;
    else
    {
        int cache_1 = LogXancestors(T->lChild, key);
        int cache_2 = LogXancestors(T->rChild, key);
        if (cache_1 == 1 || cache_2 == 1)
        {
            cout << T->data;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}