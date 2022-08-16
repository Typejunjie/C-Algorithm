#include <stdio.h>
#include <iostream>
#include "algorithm-linearStack/judgeMatching.h"

using namespace std;

int main()
{
    char str[] = "{{{}}}}";
    bool judge = judgeMatching(str);
    cout << judge;
}
