#include "../linearList.h"
/* 算法：
二分查找元素key，找到则将其与后继元素交换，
未找到则将该元素插入并使其依然有序.
时间复杂度O(n)
空间复杂度O(8)
 */
void searchOper(linearList &L, int key)
{
    int count = halfSearch(L, key);
    if (count == -1)
    {
        // 未找到元素，则将该元素插入并使其依旧有序
        int low = 0;
        int high = L.length - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (key < L.data[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        int index;
        if (high < mid)
        {
            // 将值插入到mid前
            index = mid;
        }
        else
        {
            // 将值插入到mid后
            index = mid + 1;
        }
        int number;
        int p;
        int i = index;
        number = L.data[i];
        L.data[i] = key;
        while (i < L.length + 1)
        {
            p = L.data[i + 1];
            L.data[i + 1] = number;
            number = p;
            i++;
        }
        L.length++;
        cout << "未找到元素则插入并使有序" << endl;
    }
    else if (count != L.length - 1)
    {
        // 找到了元素，与其后继交换
        int p = L.data[count];
        L.data[count] = L.data[count + 1];
        L.data[count + 1] = p;
        cout << "找到了该元素。与后继交换" << endl;
    }
    else
    {
        // 该元素为最后一个元素，不做处理
        cout << "最后一个元素不做处理" << endl;
        return;
    }
}
