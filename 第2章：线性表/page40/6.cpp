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

void swap(int *a, int i, int j)
{
    int temp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = temp;
}

int sort(int *a, int i, int j)
{
    int pivot = *(a + i);
    int left = i + 1;
    int right = j;

    while (left <= right)
    {
        if (*(a + left) <= pivot)
        {
            left++;
        }
        else
        {
            swap(a, left, right);
            right--;
        }
    }

    swap(a, i, right);
    return right;
}

void quickSort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = sort(a, left, right);
        quickSort(a, left, mid - 1);
        quickSort(a, mid + 1, right);
    }
}

void LinkListToArray(LinkList &L, int *arr)
{
    LNode *p = L->next;
    int i = 0;

    while (p)
    {
        arr[i++] = p->data;
        p = p->next;
    }
}

void ArrayToLinkList(LinkList &L, int *arr)
{
    LNode *r = L;
    for (int i = 0; i < 5; i++)
    {
        LNode *s = new LNode;
        s->data = arr[i];
        r->next = s;
        r = s;
        r->next = NULL;
    }
}

int main()
{
    LinkList L = new LNode;
    TailInsert(L);
    int *arr = new int[5];

    LinkListToArray(L, arr);
    quickSort(arr, 0, 4);
    ArrayToLinkList(L, arr);

    Print(L);
}