#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    CircularQueue()
    {
        this->size = 5;
        front = rear = 0;
        Q = new int[this->size];
        
    }
    CircularQueue(int size)
    {
    this->size = size;
    front = rear = 0;
    Q = new int[this->size];
    }
    void create(int size);
    void enqueue(int x);
    int dequeue();
    void Display();
};

void CircularQueue::enqueue(int x)
{
    if ((rear + 1) % size == front)
        cout<<"Queue is Full";
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
    cout<<endl;
}
int CircularQueue::dequeue()
{
    int x = -1;

    if (front == rear)
        cout<<"Queue is Empty\n";
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
    cout<<endl;
}
void CircularQueue::Display()
{
    int i = front + 1;

    do
    {

        cout<<Q[i]<<" ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);

    cout<<endl;
}
int main()
{
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.Display();

    cout<<q.dequeue();
    return 0;
}