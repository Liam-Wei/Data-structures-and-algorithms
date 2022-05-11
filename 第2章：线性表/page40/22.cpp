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

void SearchK(LinkList &L, int k)
{
    LNode *p, *q; //定义两个指针，分别是快、慢指针
    p = q = L->next; //同时指向第一个结点

    int count = 0;
    while (p)
    {
        //计数，先找到第k个结点
        if (count < k)
        {
            count++;
        }
        //到第k个之后，q开始行走
        else
        {
            q = q->next;
        }
        p = p->next;
    }

    //当p到尾部的时候，q的指向就是倒数第k个
    if (count < k)
    {
        cout << "查找失败" << endl;
        return;
    }

    cout << q->data << endl;
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);

    SearchK(L, 3);
}