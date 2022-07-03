#include "../linearStack.h"

/* 
算法：递归函数的非递归实现
        { 1  ,n = 0
Pn(x) = { 2x ,n = 1
        { 2xPn-1(x) - 2(n - 1)Pn-2(x) ,n > 1
 */

int recursiveFun(int n, int x)
{
    Stack S;
    initalStack(S);
    int nVal[100];
    int cache;
    nVal[0] = 1;
    nVal[1] = 2 * x;
    if (n < 2)
        return nVal[n];
    for (int j = n; j > 1; j--)
    {
        pushStack(S, j);
    }
    while (true)
    {
        cache = popStack(S);
        if (cache == 0)
            break;
        nVal[cache] = 2 * x * nVal[cache - 1] - 2 * (cache - 1) * nVal[cache - 2];
    }
    return nVal[n];
}