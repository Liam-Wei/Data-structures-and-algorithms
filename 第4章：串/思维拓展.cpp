#include <iostream>
using namespace std;
#define MAXSIZE 100

//定义串的结构
typedef struct
{
    char ch[MAXSIZE];
    int length = 0;
} String;

//为字符串赋值
void InitString(String &s, char *chars)
{
    int i = 0, k = 1;
    while (chars[i] != '\0')
    {
        s.ch[k++] = chars[i++];
        s.length++;
    }
}

//打印字符串
void Print(String s)
{
    for (int i = 0; i < s.length; i++)
    {
        cout << s.ch[i + 1];
    }
    cout << endl;
}

//获得模式串的next数组
void GetNext(String T, int next[])
{
    int j = 1, k = 0;
    next[1] = 0; //初始化第一个位置
    while (j < T.length)
    {
        //如果pj==pk或者匹配失败
        if (k == 0 || T.ch[j] == T.ch[k])
        {
            j++;
            k++;
            next[j] = k; // p[j+1]=p[j]+1
        }
        else
        {
            k = next[k]; //匹配失败，滑动窗口
        }
    }
}

//字符串朴素匹配算法
int KMPMatch(String &S, String &T, int next[])
{
    int i = 1, j = 1; //定义初始字符串指针
    while (i <= S.length && j <= T.length)
    {
        //如果匹配成功，或者第一个字符匹配失败，将二者指针后移
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j]; //匹配失败，移动模板串指针为最大公共前后缀的后一位
        }
    }
    //如果j的值大于当前模式串的长度说明，全部匹配成功
    if (j > T.length)
    {
        return i - T.length;
    }

    return -1;
}

//打印next数组值
void PrintArray(int next[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << next[i] << '\t';
    }
    cout << endl;
}

//统计模式串在主串中多少个完全匹配的子串
int CountSub(String S, String T, int next[], int n, int m)
{
    int count = 0;
    int i = 1, j = 1;
    while (i <= (n - m + 1))
    {
        while (i <= S.length && j <= T.length)
        {
            //如果匹配成功，或者第一个字符匹配失败，将二者指针后移
            if (j == 0 || S.ch[i] == T.ch[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j]; //匹配失败，移动模板串指针为最大公共前后缀的后一位
            }
        }
        //如果j的值大于当前模式串的长度说明，全部匹配成功
        if (j > T.length)
        {
            count++;
            i = i - T.length + 1;
            j = 1;
        }
        else
        {
            return count;
        }
    }

    return count;
}
int main()
{
    String S, T;
    int n = 14;
    int next[n + 1];
    char s[] = "ababaabaababab";
    char t[] = "ab";
    InitString(S, s);
    InitString(T, t);
    GetNext(T, next);
    cout << CountSub(S, T, next, n, 2);
}