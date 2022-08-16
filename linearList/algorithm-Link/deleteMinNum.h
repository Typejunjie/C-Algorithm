#include "../linkList.h"

/* 
算法：删除最小值结点
时间复杂度O(n)
空间复杂度O(1)
 */

void deleteMinNum(linkList &L)
{
    linkList nowMinNodeLast, nowNode;
    nowMinNodeLast = L;
    if(nowNode == NULL)return;
    nowNode = L;
    while (nowNode->next)
    {
        if(nowNode->next->data < nowMinNodeLast->next->data)
        {
            nowMinNodeLast = nowNode;
        }
        nowNode = nowNode->next;
    }
    linkList free = nowMinNodeLast->next;
    nowMinNodeLast->next = nowMinNodeLast->next->next;
    delete free;
}