#include "../Stack/linearCharStack.h"

int judgeLayer(char str)
{
    switch (str)
    {
    case '(':
        return 0;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
void pushChar(char *str, int &length, char value)
{
    str[length] = value;
    length++;
}
/*
算法：将中缀表达式转为后缀表达式(仅限个位数运算)
 */
bool convertsToSuffixExpress(char *str, int length, char *newStr)
{
    Stack S;
    initalStack(S);
    int nowLayer = -1, newStrL = 0, currentLayer;
    char cache[1];
    for (int i = 0; i < length - 1; i++)
    {
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            currentLayer = judgeLayer(str[i]);
            while (nowLayer >= currentLayer && S.top > 0)
            {
                cache[0] = popStack(S);
                pushChar(newStr, newStrL, cache[0]);
                nowLayer = judgeLayer(S.data[S.top - 1]);
            }
            pushStack(S, str[i]);
            nowLayer = currentLayer;
        }
        else if (str[i] == ')')
        {
            while (S.data[S.top - 1] != '(' && S.top > 0)
            {
                cache[0] = popStack(S);
                pushChar(newStr, newStrL, cache[0]);
            }
            popStack(S);
            if (S.top == 0)
                nowLayer = -1;
            else
                nowLayer = judgeLayer(S.data[S.top - 1]);
        }
        else
        {
            pushChar(newStr, newStrL, str[i]);
        }
        logStack(S);
    }
    while (S.top != 0)
    {
        pushChar(newStr, newStrL, popStack(S));
    }
    return true;
}