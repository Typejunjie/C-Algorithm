#include "../linkList.h"

/* 
算法：将单链表就地逆置
就地意为空间复杂度未O(1)
时间复杂度O(n)
空间复杂度O(1)
 */

/* 
算法实现方案：一
将第一个结点保存，再将头结点与第一个结点断开
依次把保存的结点用头插法插入到头结点后
算法实现方案：二
将前三个结点保存，头结点断开
再将三个指针中左边两个结点指针指向反转，直到所有指针反转
再将头结点指向尾结点
 */

void reverseList_1(linkList &L)
{
    if (L->next->next == NULL)return;
    linkList nowNode = L->next;
    linkList nextNode;
    L->next = NULL;
    while (nowNode)
    {
        nextNode = nowNode->next;
        nowNode->next = L->next;
        L->next = nowNode;
        nowNode = nextNode;
    }
}

void reverseList_2(linkList &L)
{
    if (L->next->next == NULL)return;
    linkList last, mid, next;
    last = L->next;
    mid = last->next;
    last->next = NULL;
    while (mid != NULL)
    {
        next = mid->next;
        mid->next = last;
        last = mid;
        mid = next;
    }
    L->next = last;
}