#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法
void HeadInsert(LinkList &L)
{
    int val = 0;
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

void DelValue(LinkList &L, int left, int right)
{
    LNode *p, *pre;
    p = L->next, pre = L;

    while (p)
    {
        if (p->data > left && p->data < right)
        {
            LNode *q = p;
            p = p->next;
            pre->next = p;
            delete q;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);

    DelValue(L, 3, 5);
    Print(L);
}