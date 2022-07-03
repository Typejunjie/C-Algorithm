#include <stdio.h>
#include <iostream>
#include "linearQueue.h"

using namespace std;

int main()
{
    Queue Q;
    initalQueue(Q);
    for (int i = 0; i < 10; i++)
    {
        push(Q, i);
    }
    log(Q);
}