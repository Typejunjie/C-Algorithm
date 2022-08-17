#include "../Stack/linearStack.h"
#include "../Queue/linearQueue.h"

/*
算法：逆置队列
时间复杂度O(n)
空间复杂度O(n)
 */

void reverseQueue(Queue &Q, Stack &S)
{
    int cache;
    while (true)
    {
        cache = popQueue(Q);
        if (cache == 0)
            break;
        pushStack(S, cache);
    }
    while (true)
    {
        cache = popStack(S);
        if (cache == 0)
            break;
        pushQueue(Q, cache);
    }
}