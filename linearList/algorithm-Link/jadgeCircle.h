#include "../linkList.h"

/*
算法：判断一个单链表是否有环
即最后一个元素的next指向了前面的某个元素
时间复杂度O(n)
空间复杂度O(1)
 */
/*
实现方案：设置两个指针一快一慢，若一段操作后两个指针相等则有环
快慢指的是一次操作往前走的距离
 */
// 将原有链表建立一个环
void createCircle(linkList &L)
{
    linkList cache, point;
    int count = 0;
    cache = L;
    while (cache->next)
    {
        if (count == 3)
            point = cache;
        cache = cache->next;
        count++;
    }
    cache->next = point;
}

bool jadgeCircle(linkList &L)
{
    linkList slow, fast;
    slow = L;
    fast = L->next;
    int count = 0;
    while (fast != slow && fast != NULL)
    {
        fast = fast->next;
        if (count % 2 == 1)
            slow = slow->next;     
        count++;   
    }
    if (fast == slow)
    {
        return true;
    }
    return false;
}