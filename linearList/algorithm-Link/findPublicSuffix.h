#include "../linkList.h"

/* 
算法：找到公共后缀起始位置
两个单词的后缀相同则可以公用一条链表作为后缀
时间复杂度O(n)
空间复杂度O(1)
 */
/* 
实现方案：先遍历链表得到长度
再重置为头结点，根据长度获得距离尾结点距离，
距离大的指针后移距离自减，相同距离同时后移
直到两指针指向统一结点
 */
// 创建有公共后缀的单链表
void createPublicSuffix(linkList &L, linkList &S)
{
    linkList Lcache, Scache;
    int count = 0;
    Scache = S->next;
    Lcache = L->next;
    while (Scache->next)
    {
        Scache = Scache->next;
    }
    while (count < 4)
    {
        Lcache = Lcache->next;
        count++;
    }
    Scache->next = Lcache;
}


linkList findPunlicSuffix(linkList &L, linkList &S)
{
    linkList Lcache, Scache;
    Lcache = L->next;
    Scache = S->next;
    int lengthL = 0;
    int lengthS = 0;
    while (Lcache)
    {
        Lcache = Lcache->next;
        lengthL++;
    }
    while (Scache)
    {
        Scache = Scache->next;
        lengthS++;
    }
    Lcache = L->next;
    Scache = S->next;
    int distenceL, distenceS;
    distenceL = lengthL;
    distenceS = lengthS;
    while (Lcache != Scache)
    {
        if (distenceL < distenceS)
        {
            Scache = Scache->next;
            distenceS--;
        }
        else if (distenceL > distenceS)
        {
            Lcache = Lcache->next;
            distenceL--;
        }
        else
        {
            Lcache = Lcache->next;
            Scache = Scache->next;
            distenceL--;
            distenceS--;
        }
    }
    return Scache;
}