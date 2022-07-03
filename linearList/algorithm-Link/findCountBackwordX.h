#include "../linkList.h"

/* 
算法：找到链表中倒数第x个元素并输出
要求不影响原链表结构
时间复杂度O(n)
空间复杂度O(1)
 */

int findCountBackwordX(linkList &L, int x)
{
    linkList nowNode, backNode;
    backNode = L;
    nowNode = L->next;
    int count = 1;
    while (nowNode)
    {
        if (count == x)
        {
            backNode = L->next;
        }
        if (count > x)
        {
            backNode = backNode->next;
        }
        count++;
        nowNode = nowNode->next;
    }
    if (backNode == L)
    {
        return 0;
    }
    return backNode->data;
}