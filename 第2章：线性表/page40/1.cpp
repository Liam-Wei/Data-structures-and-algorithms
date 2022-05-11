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

void DelValue(LinkList &L, int x)
{
    if (L == NULL)
    {
        return;
    }

    LNode *p;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        delete p;
        DelValue(L, x);
    }
    else
    {
        DelValue(L->next, x);
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);

    DelValue(L, 2);
    Print(L);
}