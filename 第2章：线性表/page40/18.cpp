#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

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

        if (cin.get() == '\n')
        {
            break;
        }
    }

    r->next = L;
}

// 遍历输出链表元素
void Print(LinkList L)
{
    LNode *p = L->next;
    while (p != L)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

void ConnectList(LinkList &LA, LinkList &LB)
{
    LNode *pa, *pb; //定义两个工作指针
    pa = LA->next;
    pb = LB->next;

    //找到LA的尾指针
    while (pa->next != LA)
    {
        pa = pa->next;
    }

    //找到LB的尾指针
    while (pb->next != LB)
    {
        pb = pb->next;
    }

    //修改指针指向
    pa->next = LB->next;
    pb->next = LA;
}

int main()
{
    LinkList LA = new LNode;
    LinkList LB = new LNode;

    TailInsert(LA);
    TailInsert(LB);

    ConnectList(LA, LB);

    Print(LA);
}