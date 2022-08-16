#include "../graph-matrix.h"

/* 
算法：判断是否存在El路径
当顶点度为奇数的个数不大于偶数度的顶点时则存在El路径
时间复杂度O(n^2)
空间复杂度O(1)
 */

bool jadgeElroute(Gmatrix &G)
{
    int countOdd = 0, countEven = 0;
    int cache;
    for (int i = 0; i < G.countPoint; i++)
    {
        cache = 0;
        for (int j = 0; j < G.countPoint; j++)
        {
            if (G.data[j][i] == 1)
            {
                cache++;
            }
        }
        if (cache == 0)
            continue;
        if (cache % 2 == 1)
        {
            countOdd++;
        }
        else
        {
            countEven++;
        }
    }
    cout << countOdd << "|" << countEven << endl;
    if (countOdd <= countEven)
        return true;
    return false;
}