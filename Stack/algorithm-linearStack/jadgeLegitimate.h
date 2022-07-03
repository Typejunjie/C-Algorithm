#include "../linearStack.h"

/* 
算法： 判断一个序列是否合法
时间复杂度O(n)
空间复杂度O(1)
 */

bool jadgeLegitimate(int* Array, int length)
{
    Stack S;
    initalStack(S);
    int cache;
    for (int i = 0; i < length; i++)
    {
        if (Array[i] == 0)
        {
            cache = pop(S);
            if (cache == 0)
            {
                return false;
            }            
        }
        else
        {
            push(S, Array[i]);
        }
    }
    return true;
}
