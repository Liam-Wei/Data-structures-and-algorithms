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

void PublicNode(LinkList &LA, LinkList &LB)
{
    int lena = 0, lenb = 0;
    LNode *p = LA->next;
    while (p)
    {
        lena++;
        p = p->next;
    }
    p = LB->next;
    while (p)
    {
        lenb++;
        p = p->next;
    }

    LNode *longList, *shortList;
    int dist = 0;
    if (lena > lenb)
    {
        longList = LA->next;
        shortList = LB->next;
        dist = lena - lenb;
    }
    else
    {
        longList = LB->next;
        shortList = LA->next;
        dist = lenb - lena;
    }

    while (dist--)
    {
        longList = longList->next;
    }

    while (longList != NULL)
    {
        if (longList == shortList)
        {
            cout << longList->data;
            return;
        }
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
}

int main()
{
    LNode *p1 = new LNode;

    LNode *q1 = new LNode;
    LNode *q2 = new LNode;
    LNode *q3 = new LNode;

    // 公共结点
    LNode *m1 = new LNode;
    m1->data = 99999;
    LNode *m2 = new LNode;

    m1->next = m2;
    m2->next = NULL;
    p1->next = m1;

    q1->next = q2;
    q2->next = q3;
    q3->next = m1;

    PublicNode(p1, q1);
}