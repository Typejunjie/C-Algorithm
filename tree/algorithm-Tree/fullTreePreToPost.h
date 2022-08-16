#include "../linearQueue.h"

using namespace std;

/* 
算法：由满二叉树的先序序列求出其后序序列
 */

int i = -1;

void fullTreePreToPost(int *pre, int *post, int pl, int pr)
{
    if (i == -1)
        i = pr;
    post[i] = pre[pl];
    i--;
    pl++;
    int half = (pl + pr) / 2;
    if (pl > pr)
        return;
    fullTreePreToPost(pre, post, half + 1, pr);
    fullTreePreToPost(pre, post, pl, half);
}