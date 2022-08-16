#include "linkList.h"
#include <math.h>


void testBug(linkList &L)
{
    linkList cache, point;
    point = L->next;
    while (point)
    {
        cache = point;
        while (cache->next)
        {
            if (abs(point->data) == abs(cache->next->data))
            {
                cache->next = cache->next->next;
                continue;
            }
            cache = cache->next;
        }
        point = point->next;
    }
}