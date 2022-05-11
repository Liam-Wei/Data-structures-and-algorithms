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

void SubNode(LinkList &LA, LinkList &LB)
{
    LNode *p, *q, *pre; // LA、LB的工作结点，和每次开始的比较结点
    p = LA->next;
    q = LB->next;
    pre = p;

    while (p && q)
    {
        //如果二者相等，指针后移继续匹配
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        //不等，将pre开始指针向后偏移一位，q重新开始
        else
        {
            pre = pre->next;
            p = pre;
            q = LB->next;
        }
    }

    if (q)
    {
        cout << "B不是A的子序列" << endl;
        return;
    }

    cout << "B是A的子序列" << endl;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;

    TailInsert(LA);
    TailInsert(LB);

    SubNode(LA, LB);
}