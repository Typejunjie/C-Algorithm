#include "../linearQueue.h"

/*
算法：依据层次遍历和结点的度构造孩子兄弟存储的树
 */

void createTreeInArrangeAndDegree(linkT &T, int (*Array)[2], int length)
{
    Tree *nodeList[20];
    linkT cache;
    int value, count = 1;
    for (int i = 0; i < length; i++)
    {
        value = Array[i][0];
        cache = createT(value);
        nodeList[i] = cache;
    }
    for (int j = 0; j < length; j++)
    {
        if (Array[j][1] > 0)
        {
            nodeList[j]->lChild = nodeList[count];
        }
        if (Array[j][1] > 1)
        {
            for (int i = 0; i < Array[j][1] - 1; i++)
            {
                nodeList[i + count]->rChild = nodeList[i + 1 + count];
            }
        }
        count = count + Array[j][1];
    }
    T = nodeList[0];
}