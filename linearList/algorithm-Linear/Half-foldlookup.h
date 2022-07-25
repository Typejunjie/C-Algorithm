#include "../linearList.h"

/* 
算法：折半查找
时间复杂度O(logn)
空间复杂度O(1)
 */

int halfSearch(linearList &L, int key)
{
    int low = 0;
    int high = L.length - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] == key)
        {
            return mid;
        }
        else if (key < L.data[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}