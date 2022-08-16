#include "../dualCircleList.h"

/* 
算法：判断链表是否对称
时间复杂度O(n)
空间复杂度O(1)
 */

bool jadgeSymmetry(circleList &L)
{
    circleList left, right;
    left = L->next;
    right = L->prior;
    while (right != left && left->next != right )
    {
        if (right->data != left->data)
        {
            return false;
        }
        left = left->next;
        right = right->prior;
    }
    if (right == left)
       return false;
    else
       return true;
}
