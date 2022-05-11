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

//字符串朴素匹配算法
int NaiveMatch(String &S, String &T)
{
    int i = 1, j = 1; //初始化指针，同时指向主串和模式串的第一个位置
    while (i <= S.length && j <= T.length)
    {
        //如果对应字符相等，指针向后偏移一位
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        //发生失配
        else
        {
            //i-j是指向当前匹配开始的前一个位置，+1到本次开始匹配位置，+2到本次开始匹配的下一个位置
            i = i - j + 2; //主串指针指向当前比较开始的下一个位置
            j = 1; //模式串指向第一位置重新开始
        }
    }
    //如果j的值大于当前模式串的长度说明，全部匹配成功
    if (j > T.length)
    {
        return i - T.length;
    }
    
    return -1;
}

int main()
{
    String S, T;
    char s[] = "googlegooalgelgoole";
    char t[] = "goole";
    InitString(S, s);
    InitString(T, t);
    cout << NaiveMatch(S, T);
}