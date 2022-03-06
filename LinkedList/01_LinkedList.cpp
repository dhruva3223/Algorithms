#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
    int Sum();
    int Max();
    int Min();
    int LinearSearch(Node *p, int key);
    int isSorted(struct Node *p);
    void RemoveDuplicate(struct Node *p);
    void Reverse(struct Node *p)
};
LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int LinkedList::Length()
{
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first;
    if (index < 0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int LinkedList::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;
    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
int LinkedList::Sum()
{
    Node *p = first;
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int LinkedList::Max()
{
    Node *p = first;
    int max = INT32_MIN;
    ;
    while (p)
    {
        if (max < p->data)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int LinkedList::Min()
{
    Node *p = first;
    int min = INT32_MAX;
    ;
    while (p)
    {
        if (min > p->data)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}
int LinkedList::LinearSearch(Node *p, int key)
{
    Node *q = first;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p->data;
        }
        q = p;
        p = p->next;
    }
    return -1;
}
int LinkedList::isSorted(Node *p)
{
    int x = INT32_MIN;

    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}
void LinkedList::RemoveDuplicate(Node *p)
{
    struct Node *q = p->next;

    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
void LinkedList::Reverse(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    LinkedList l(A, 5);
    l.Display();
    l.Insert(3, 15);
    l.Delete(1);
    cout << "The length of the Linkedlist is: " << l.Length() << endl;
    l.Display();
    // cout<<l.Sum();
    cout << l.Max();
    return 0;
}