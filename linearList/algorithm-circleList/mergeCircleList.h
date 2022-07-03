#include "../dualCircleList.h"

/* 
算法：合并两个循环双链表
要求合并后依旧为循环双链表
时间复杂度O(1)
空间复杂度O(1)
 */

void mergeList(circleList &L, circleList &S)
{
    circleList cache;
    cache = L->prior;
    cache->next = S->next;
    S->prior->next = L;
}