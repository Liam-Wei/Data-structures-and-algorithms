#include <iostream>
#include <string.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法
void HeadInsert(LinkList &L)
{
    int val = '\0';
    while (cin >> val)
    {
        LNode *s = new LNode;
        s->data = val;
        s->next = L->next;
        L->next = s;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

// 尾插法
void TailInsert(LinkList &L)
{
    int val = 0;
    LNode *r = L;
    while (cin >> val)
    {
        LNode *s = new LNode;
        s->data = val;
        r->next = s;
        r = s;
        r->next = NULL;

        if (cin.get() == '\n')
        {
            break;
        }
    }
}

// 遍历输出链表元素
void Print(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

void DelValue(LinkList &L, int n)
{
    LNode *p, *r, *pre;   //定义工作指针、前驱指针
    int x = 0;            //保存绝对值
    int arr[n + 1] = {0}; //定义辅助数组初始值赋值为0

    p = L->next;
    pre = L;

    while (p)
    {
        x = p->data > 0 ? p->data : -p->data; //保存绝对值

        //如果事先不存在，将对应位置赋值为1
        if (arr[x] == 0)
        {
            arr[x] = 1;
            pre = p;
            p = p->next;
        }
        //如果之前存在，则将当前结点删除
        else
        {
            r = p->next;
            pre->next = p->next;
            delete p;
            p = r;
        }
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);
    Print(L);

    DelValue(L, 30);
    Print(L);
}