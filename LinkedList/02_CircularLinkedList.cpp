#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList(int A[], int n);
    void Display();
    Node *getHead() { return head; }
    ~CircularLinkedList();
};

CircularLinkedList::CircularLinkedList(int *A, int n)
{

    Node *t;
    Node *tail;

    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList::Display()
{
    Node *p = head;
    do
    {
        cout << p->data << " " ;
        p = p->next;
    } while (p != head);
    cout << endl;
}

CircularLinkedList::~CircularLinkedList()
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }

    while (p != head)
    {
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head)
    {
        delete head;
        head = nullptr;
    }
}