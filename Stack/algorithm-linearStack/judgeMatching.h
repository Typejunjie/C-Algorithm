#include "../linearCharStack.h"

/*
算法：判断括号匹配
以 \0 为结尾标示
允许括号中存在其他非括号元素，但不能与 \0 相同
 */
bool judgeMatching(char *str)
{
    Stack S;
    initalStack(S);
    int cache = 0;
    char value[1];
    while (str[cache] + str[cache] != '\0')
    {
        if (str[cache] == '[' || str[cache] == '(' || str[cache] == '{')
        {
            pushStack(S, str[cache]);
        }
        else if (str[cache] == ']' || str[cache] == ')' || str[cache] == '}')
        {
            value[0] = popStack(S);
            if (value[0] == '0')         // 用是否为字符串0判断栈空
                return false;
            if (value[0] == str[cache])
                return false;
        }
        cache++;
    }
    if (S.top != 0)
        return false;
    return true;
}